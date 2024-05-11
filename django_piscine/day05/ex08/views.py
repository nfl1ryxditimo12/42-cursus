from django.shortcuts import redirect, render
from django.conf import settings
from django.http import HttpResponse, response
from django.forms import Form

# Create your views here.

import psycopg2

def init(request):
    try:
        database = psycopg2.connect(
            dbname=settings.DATABASES['default']['NAME'],
            user=settings.DATABASES['default']['USER'],
            password=settings.DATABASES['default']['PASSWORD'],
            host=settings.DATABASES['default']['HOST'],
            port=settings.DATABASES['default']['PORT'],
        )

        with database.cursor() as cur:
            cur.execute("""
            CREATE TABLE ex08_planets(
                id SERIAL PRIMARY KEY,
                name VARCHAR(64) UNIQUE NOT NULL,
                climate VARCHAR,
                diameter INT,
                oribital_period INT,
                population BIGINT,
                rotation_period INT,
                surface_water REAL,
                terrain VARCHAR(128)
            );

            CREATE TABLE ex08_people(
                id SERIAL PRIMARY KEY,
                name VARCHAR(64) UNIQUE NOT NULL,
                birth_year VARCHAR(32),
                gender VARCHAR(32),
                eye_color VARCHAR(32),
                hair_color VARCHAR(32),
                height INT,
                mass REAL,
                homeworld VARCHAR(64) REFERENCES ex08_planets(name)
            );
            """)

            database.commit()
            return HttpResponse('OK')
    except Exception as e:
        return HttpResponse(e)

def populate(request):
    with open('ex08/planets.csv', 'rb') as f:
        planets = [line for line in f.readlines()]
        print(planets)
    return redirect(request.path)