from d05 import settings
from django.http import HttpRequest, HttpResponse

import psycopg2

# Create your views here.

def ex00(request: HttpRequest):
    try:
        db = psycopg2.connect(
            dbname=settings.DATABASES['default']['NAME'],
            user=settings.DATABASES['default']['USER'],
            password=settings.DATABASES['default']['PASSWORD'],
            host=settings.DATABASES['default']['HOST'],
            port=settings.DATABASES['default']['PORT'],
        )
        with db.cursor() as cur:
            cur.execute("""
            CREATE TABLE ex00_movies(
                title VARCHAR(64) UNIQUE NOT NULL,
                episode_nb INTEGER PRIMARY KEY,
                opening_crawl TEXT,
                director VARCHAR(32) NOT NULL,
                producer VARCHAR(128) NOT NULL,
                release_data DATE NOT NULL
                );
            """)
            cur.execute('commit')
        return HttpResponse('OK')
    except Exception as e:
        return HttpResponse(e)
    