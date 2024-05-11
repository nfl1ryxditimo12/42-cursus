from django.forms.widgets import FILE_INPUT_CONTRADICTION
from django.shortcuts import redirect, render
from django.conf import settings
from django.http import HttpResponse, response
from django.forms import Form

# Create your views here.

import psycopg2

table_name = 'ex04_movies'

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
            CREATE TABLE ex04_movies(
                title VARCHAR(64) UNIQUE NOT NULL,
                episode_nb INTEGER PRIMARY KEY,
                opening_crawl TEXT,
                director VARCHAR(32) NOT NULL,
                producer VARCHAR(128) NOT NULL,
                release_date DATE NOT NULL
                );
            """)
        database.commit()
        return HttpResponse('OK')
    except Exception as e:
        return HttpResponse(e)

def populate(request):
    try:
        database = psycopg2.connect(
            dbname=settings.DATABASES['default']['NAME'],
            user=settings.DATABASES['default']['USER'],
            password=settings.DATABASES['default']['PASSWORD'],
            host=settings.DATABASES['default']['HOST'],
            port=settings.DATABASES['default']['PORT'],
        )

        data = [
            {
                'episode_nb': 1,
                'title': 'The Phantom Menace',
                'director': 'George Lucas',
                'producer': 'Rick McCallum',
                'release_date': '1999-05-19'
            },

            {
                'episode_nb': 2,
                'title': 'Attack of the Clones',
                'director': 'George Lucas',
                'producer': 'Rick McCallum',
                'release_date': '2002-05-16'
            },

            {
                'episode_nb': 3,
                'title': 'Revenge of the Sith',
                'director': 'George Lucas',
                'producer': 'Rick McCallum',
                'release_date': '2005-05-19'
            },
            
            {
                'episode_nb': 4,
                'title': 'A New Hope',
                'director': 'George Lucas',
                'producer': 'Gary Kurtz, Rick McCallum',
                'release_date': '1977-05-25'
            },

            {
                'episode_nb': 5,
                'title': 'The Empire Strikes Back',
                'director': 'Irvin Kershner',
                'producer': 'Gary Kurtz, Rick McCallum',
                'release_date': '1980-05-17'
            },

            {
                'episode_nb': 6,
                'title': 'Return of the Jedi',
                'director': 'Richard Marquand',
                'producer': 'Howard G. Kazanjian, George Lucas, Rick McCallum',
                'release_date': '1983-05-25'
            },

            {
                'episode_nb': 7,
                'title': 'The Force Awakens',
                'director': 'J. J. Abrams',
                'producer': 'Kathleen Kennedy, J. J. Abrams, Bryan Burk',
                'release_date': '2015-12-11'
            },
        ]

        insert_data = """
        INSERT INTO ex04_movies
        (
            episode_nb,
            title,
            director,
            producer,
            release_date
        )
        VALUES
        (
            %s, %s, %s, %s, %s
        );
        """

        with database.cursor() as cur:
            for d in data:
                try:
                    cur.execute(insert_data, [
                        d['episode_nb'],
                        d['title'],
                        d['director'],
                        d['producer'],
                        d['release_date'],
                    ])
                    database.commit()
                except psycopg2.DatabaseError as e:
                    database.rollback()
        return HttpResponse('OK')
    except Exception as e:
        return HttpResponse(e)

def display(request):
    try:
        database = psycopg2.connect(
            dbname=settings.DATABASES['default']['NAME'],
            user=settings.DATABASES['default']['USER'],
            password=settings.DATABASES['default']['PASSWORD'],
            host=settings.DATABASES['default']['HOST'],
            port=settings.DATABASES['default']['PORT'],
        )
        with database.cursor() as cur:
            cur.execute("SELECT * FROM ex04_movies")
            movies = cur.fetchall()
            if len(movies) == 0:
                return HttpResponse('No data available')
        return render(request, 'ex04/display.html', {'movies': movies})
    except Exception:
        return HttpResponse("No data available")

def remove(request):
    try:
        template_name = 'ex04/remove.html'
        database = psycopg2.connect(
            dbname=settings.DATABASES['default']['NAME'],
            user=settings.DATABASES['default']['USER'],
            password=settings.DATABASES['default']['PASSWORD'],
            host=settings.DATABASES['default']['HOST'],
            port=settings.DATABASES['default']['PORT'],
        )

        cur = database.cursor()

        if request.method == 'POST':
            
            form = Form(request.POST)

            key = request.POST.get('select')
            if form.is_valid() and key:
                try:
                    cur.execute(f"DELETE FROM ex04_movies WHERE title='{key}'")
                    database.commit()
                except Exception as e:
                    HttpResponse('No data available')

        form = Form()

        try:
            cur.execute("""SELECT * FROM ex04_movies""")
            response = cur.fetchall()
            data = []
            for res in response:
                data.append(res[0])
        
        except Exception as e:
            return HttpResponse('No data available')
        
        database.close()

    except psycopg2.Error as e:
        return HttpResponse(e)

    if response:
        return render(request, template_name, {'data': data, 'form': form})
    else:
        return HttpResponse('No data available')