from django import forms

class RemoveFrom(forms.Form):

    choice = forms.ChoiceField(choices=(), required=True)