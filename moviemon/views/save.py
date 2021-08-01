from moviemon.util.data import save_game_data, load_game_data
from django.shortcuts import render, redirect
from django.views.generic import TemplateView

state = {'slot': 0}

class Save(TemplateView):
    template_name = 'save.html'
    context = {}

    def get(self, request):
        key = request.GET.get('key', None)
        print(state['slot'])
        if key is not None:
            if key == 'up':
                if state['slot'] > 0:
                    state['slot'] -= 1
            elif key == 'down':
                if state['slot'] < 2:
                    state['slot'] += 1 
            if key == 'a':
                save_game_data(('A', 'B', 'C')[state['slot']])
            elif key == 'b':
                return redirect('options')
            return redirect(request.path)
        
        slots = load_game_data()
        score = 'Free' if slots.get(
            'A', None) is None else slots.get('A').get('score', 'Free')
        self.context['A'] = "Slot 🅰 : {}".format(score)
        score = 'Free' if slots.get(
            'B', None) is None else slots.get('B').get('score', 'Free')
        self.context['B'] = "Slot 🅱 : {}".format(score)
        score = 'Free' if slots.get(
            'C', None) is None else slots.get('C').get('score', 'Free')
        self.context['C'] = "Slot 🅲 : {}".format(score)
        self.context['active'] = state['slot']

        return render(request, self.template_name, self.context)