import logging
from django.http import HttpRequest
from django.shortcuts import render, redirect
from django.conf import settings
from . import forms

# Create your views here.

def submit(request: HttpRequest):
    logger = logging.getLogger('history')

    if request.method == 'POST':
        form = forms.History(request.POST)
        if form.is_valid():
            logger.info(form.cleaned_data['history'])
        return redirect('/ex02')
    try:
        f = open(settings.LOG_FILE, 'r')
        history = [line for line in f.readlines()]
    except:
        history = []

    return render(request, 'ex02/submit.html', {'form': forms.History(), 'history': history})