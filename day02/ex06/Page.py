from elements import *

class Page:
    def __init__(self, elem: Elem()) -> None:
        if not isinstance(elem, Elem):
            raise Elem.ValidationError()
        self.elem = elem
    
    def __str__(self) -> str:
        result = ''
        if isinstance(self.elem, Html):
            result += "<!DOCTYPE html>\n"
        result += str(self.elem)
        return result
        
    def write_to_file(self, path: str) -> None:
        f = open(path, 'w')
        f.write(self.__str__())

    def is_valid(self) -> bool:
        return self.__norm_check(self.elem)

    def __norm_check(self, elem: Elem()) -> bool:
        if not (isinstance(elem, (Html, Head, Body, Title, Meta, Img, Table, Th, Tr, Td, Ul, Ol, Li, H1, H2, P, Div, Span, Hr, Br)) or type(elem) == Text):
            return False
        if type(elem) == Text or isinstance(elem, Meta):
            return True
        if isinstance(elem, Html) and len(elem.content) == 2 and type(elem.content[0]) == Head and type(elem.content[1]) == Body:
            if (all(self.__norm_check(el) for el in elem.content)):
                return True
        elif isinstance(elem, Head) and [isinstance(el, Title) for el in elem.content].count(True) == 1:
            if (all(self.__norm_check(el) for el in elem.content)):
                return True
        elif isinstance(elem, (Body, Div)) and all([isinstance(el, (H1, H2, Div, Table, Ul, Ol, Span)) or type(el) == Text for el in elem.content]):
            if all(self.__norm_check(el) for el in elem.content):
                return True
        elif isinstance(elem, (Title, H1, H2, Li, Th, Td)) and len(elem.content) == 1 and type(elem.content[0]) == Text:
            return True
        elif isinstance(elem, P) and all([isinstance(el, Text) for el in elem.content]):
            return True
        elif isinstance(elem, Span) and all([isinstance(el, (Text, P)) for el in elem.content]):
            if all(self.__norm_check(el) for el in elem.content):
                return True
        elif isinstance(elem, (Ul, Ol)) and len(elem.content) > 0 and all([isinstance(el, Li) for el in elem.content]):
            if all(self.__norm_check(el) for el in elem.content):
                return True
        elif isinstance(elem, Tr) and len(elem.content) > 0 and all([isinstance(el, (Th, Td)) for el in elem.content]) and all([type(el) == type(elem.content[0]) for el in elem.content]):
            return True
        elif isinstance(elem, Table) and all([isinstance(el, Tr) for el in elem.content]):
            return True
        return False


if __name__ == "__main__":

    valid = Html([ Head([Title([])]), Body([]) ])
    print(f'valid: {Page(valid).is_valid()}\n')
    
    invalid_no_title = Html([Head([]), Body([])])
    print(f'invalid_no_title: {Page(invalid_no_title).is_valid()}\n')

    invalid_order = Html([Body([]), Head([Title([])])])
    print(f'invalid_order: {Page(invalid_order).is_valid()}\n')

    invalid_body_div = Html([Head([]), Body([Body([Title([])])])])
    print(f'invalid_body_div: {Page(invalid_body_div).is_valid()}\n')

    invalid_not_text = Html([Head([Title([]), Body([])])])
    print(f'invalid_: {Page(invalid_body_div).is_valid()}\n')

    table = Table([P([])])
    print(f'table: {Page(table).is_valid()}\n')

    tr = Tr([P([])])
    print(f'Tr: {Page(table).is_valid()}\n')

    ul = Ul([P([])])
    print(f'Ul: {Page(ul).is_valid()}\n')

    ol = Ul([P([])])
    print(f'Ul: {Page(ul).is_valid()}\n')


    html = Html(\
        [\
            Head( [ 
                Title([Text("Hello ground!")]), \
                Meta([], {'charset':"utf-8"})
                ] ), \
            Body( [ H1(Text("Oh no, not again!")), \
                Img([], {'src':"http://i.imgur.com/pfp3T.jpg"}),\
                Table( [Tr([Th([Text("hello")]), Th([Text("world")])])] ),\
                Ul( [ Li([Text("one")]), Li([Text("two")]), Li([Text("three")]) ] ),\
                Hr([]),\
                Ol( [ Li([Text("ONE")]), Li([Text("TWO")]), Li([Text("THREE")]) ] ),\
                P([Text("""\
                    Python\n
                    Django\n
                    Piscine\n""")]),\
                Br([]),\
                Div([Text("End")])
                     ] )\
        ] \
        )
    print(valid)
    page = Page(html)
    page.write_to_file("test.html")