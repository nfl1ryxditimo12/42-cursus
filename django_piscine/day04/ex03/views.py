from django.shortcuts import render

# Create your views here.

def color(request):
    step = 255 / 50
    context = {
        'range': [
            "{:02X}".format(int(i * step)) for i in range(50)
        ]
    }
    return render(request, 'ex03/color.html', context)