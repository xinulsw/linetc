


Logowanie i wylogowywanie
**************************

Skoro użytkownicy mogą się rejestrować, trzeba umożliwić im również logowanie
i wylogowywanie z serwisu. Również to zadanie można zrobić dwojako.
Pierwszy sposób to tak jak w przypadku rejestracji stworzenie widoków
w pliku :file:`views.py` i powiązanie ich z adresami w pliku :file:`urls.py`.

Na początku jak zawsze importujemy wymagane funkcje, później dopisujemy
widok ``loguj()`` i ``wyloguj()`` w pliku :file:`views.py`:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: views_z4.py
    :linenos:
    :lineno-start: 37
    :lines: 37-

Podobnie jak w przypadku rejestrowania użytkowników, korzystamy z wbudowanego w Django
formularza logowania ``AuthenticationForm``. Dzięki temu nie musimy
"ręcznie" sprawdzać poprawności podanych danych, robi to metoda ``is_valid()``
formularza. Jeżeli nie zwróci ona błędu, możemy zalogować użytkownika za
pomocą funkcji ``login()``, której przekazujemy obiekty ``HttpRequest``
(przesłane żądanie) i ``User`` – obiekt użytkownika zwrócony przez metodę
``get_user()`` formularza.

Wylogowanie polega na użyciu funkcji ``logout(request)`` – wyloguje ona
użytkownika, którego dane zapisane są w przesłanym żądaniu.

Jak widać, do logowania potrzebujemy szablonu. Najprościej utworzyć go
na podstawie szablonu :file:`rejestruj.html`. Otwórzmy go i zapiszmy do
pliku :file:`~/czat/czat/templates/czat/loguj.html`. Później wystarczy
dostosować wywietlany tekst. Szablon z uwzględnieniem zmian wprowadzonych
w ćwiczeniu 2. może wyglądać tak:

.. raw:: html

    <div class="code_no">Plik loguj.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: loguj_z4.html
    :linenos:

Pozostaje skojarzenie odpowiednich adresów URL z utworzonymi widokami.
W pliku :file:`urls.py` dopisujemy reguły:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls_z4.py
    :linenos:
    :emphasize-lines: 4-5
    :lineno-start: 10
    :lines: 10-

Możesz przetestować działanie dodanych funkcji wywołując w przeglądarce adresy:
``127.0.0.1:8000/loguj`` i ``127.0.0.1:8000/wyloguj``. Przykładowy formularz
wygląda tak:

.. figure:: img/czat15log.png

.. note::

    **Podsumujmy**: działanie wszystkich omówionych do tej pory widoków jest podobne.
    Po przejściu pod adres określony w pliku :file:`urls.py`, np. *127.0.0.1:8000/loguj/*,
    wywoływany jest powiązany z nim widok zdefiniowany w pliku :file:`views.py`,
    np. ``loguj()``. Tego typu operacja generuje żądanie typu :term:`GET`,
    w odpowiedzi na które zwracany jest szablon (np. :file:`loguj.html`)
    wyświetlający przekazny do niego formularz (np. ``AuthenticationForm``).

    Po wypełnieniu formularza użytkownik wciska odpowiedni przycisk, który
    inicjuje żądanietypu :term:`POST`, a więc przesyłanie danych na serwer.
    Widoki ``rejestruj()`` i ``loguj()`` wychwytują i przetwarzają takie żądania,
    tj. rejestrują lub logują użytkownika. W odpowiedzi użytkownik
    zostaje przekierowany z odopiwednim komunikatem na stonę główną.

Ćwiczenie 3
=================

Adresów logowania i wylogowywania nikt w serwisach nie wpisuje ręcznie.
Wstaw zatem odpowiednie linki do szablonu strony głównej. Użytkownik
niezalogowany powinien zobaczyć odnośnik *Zaloguj*, użytkownik
zalogowany – *Wyloguj*. Przykładowe strony mogą wyglądać tak:

.. figure:: img/czat16log.png

.. figure:: img/czat17log.png