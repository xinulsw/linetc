Czat (cz. 3)
#########################

Poniższy materiał koncentruje się na obsłudze szablonów (ang. *temaplates*)
wykorzystywanych w Django. Stanowi kontynuację projektu zrealizowanego
w scenariuszu :ref:`Czat (cz. 2) <czat-app2>`.

Na początku pobierz :download:`archiwum <czatpro3_z01.zip>` z potrzebnymi plikami
i rozpakuj je w katalogu domowym użytkownika.

Szablony
*****************

Zapewne zauważyłeś, że większość kodu w szablonach i stronach
HTML, które z nich powstają, powtarza się albo jest bardzo podobna.
Biorąc pod uwagę schematyczną budowę stron WWW jest to nieuniknione.

Szablony, jak można było zauważyć, składają się ze **zmiennych** i **tagów**.
Zmienne, które ujmowane są w podwójne nawiasy sześciokątne ``{{ zmienna }}``,
zastępowane są konkretnymi wartościami. Tagi z kolei, oznaczane notacją
``{% tag %}``, tworzą mini-język szablonów i pozwalają kontrolować logikę budowania treści.
Najważniejsze tagi, ``{% if warunek %}``, ``{% for wyrażenie %}``, ``{% url nazwa %}``
– już stosowaliśmy.

Spróbujmy uprościć i ujednolicić nasze szablony. Zacznijmy od szablonu
bazowego, który umieścimy w pliku :file:`~/czatpro3/czat/templates/czat/baza.html`:

.. raw:: html

    <div class="code_no">Plik *baza.html*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: baza_z02.html
    :linenos:

Jest to zwykły tekstowy dokument, zawierający schemat strony utworzony z
wymaganych znaczników HTML oraz bloki zdefiniowane za pomocą tagów mini-języka
szablonów ``{% block %}``. W pliku tym umieszczamy stałą i wspólną strukturę stron w serwisie
(np. nagłówek, menu, sekcja treści, stopka itp.) oraz wydzielamy bloki,
których treść będzie można zmieniać w szablonach konkretnych stron.

Wykorzystując szablon podstawowy, zmieniamy stronę główną, czyli plik
:file:`index.html`:

.. raw:: html

    <div class="code_no">Plik *index.html*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: index_z02.html
    :linenos:

Jak widać, szablon dziedziczy z szablonu bazowego – tag ``{% extends plik_bazowy %}``.
Dalej podajemy zawartość bloków, które są potrzebne na danej stronie.

Postępując na tej samej zasadzie modyfikujemy szablon rejestracji:

.. raw:: html

    <div class="code_no">Plik *rejestruj.html*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: rejestruj_z02.html
    :linenos:

**Ćwiczenie:** Wzorując się na podanych przykładach zmień pozostałe szablony tak, aby opierały się na szablonnie bazowym.
Następnie przetestuj działanie aplikacji. Wygląd stron nie powinien ulec zmianie!



Style, skrpyty, pliki
************************

Nasze szablony zyskały na zwięzłości i przejrzystości, ale nadal pozbawione
są elementarnych dla dzisiejszych stron WWW zasobów, takich jak
style CSS, skrypty JavaScript czy zwykłe obrazki. Jak je dołączyć?

Przede wszystkim potrzebujemy osobnego katalogu :file:`~czatpro/czat/static/czat`.
W terminalu w katalogu projektu (!) wydajemy polecenie:

.. raw:: html

    <div class="code_no">Terminal. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: bash

    ~/czatpro$ mkdir -p czat/static/czat
    ~/czatpro$ cd czat/static/czat
    ~/czatpro/czat/static/czat$ mkdir css js img

W utworzonym katalogu tworzy się zazwyczaj podkatalogi dla różnych typów
zasobów, np. :file:`css`, :file:`js` czy :file:`img`. Sugerujemy, żeby
je utworzyć.

Teraz tworzymy również przykładowy plik :file:`~/czatpro/czat/static/czat/css/style.css`:

.. raw:: html

    <div class="code_no">Plik style.css nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: css
.. literalinclude:: style_z11.css
    :linenos:

Do podkatalogu :file:`~/czat/czat/static/czat/img` wrzucamy obrazki z podanego
:download:`archiwum <img.zip>`. Wreszcie zmieniamy szablon podstawowy:

.. raw:: html

    <div class="code_no">Plik baza.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: baza_z11.html
    :linenos:
    :lines: 2, 7-8, 33-37

Kod z linii 1. ``{% load staticfiles %}`` umieszczamy na samym początku
dokumentu. Konfiguruje on ścieżkę do zasobów. Kod z linii 3. wklejamy
za znacznikiem ``<title>`` w sekcji ``<head>``. Ilustruje on, jak dołączamy
style czy skrypty, mianowicie używamy tagu ``{% static plik %}``. Wreszcie
kod z linii 5-8 zawierający znacznik ``<div>`` z obrazkami wstawiamy
na końcu pliku przed znacznikiem zamykającym ``</body>``. Widzimy tu,
jak wstawiać obrazki. Wygląd strony głównej po zmianach:

.. figure:: img/czat22szabl.png

Ćwiczenie 10
==============

W szablonie bazowym stwórz osobny block umożliwiający zastępowanie wstawionych
obrazków. Zmień dowolny szablon inny niż strona główna tak, aby wyświetlał
inne obrazki. Pamiętaj o zapisaniu dodatkowych obrazków do odpowiedniego katalogu!

.. tip::

    Tag ``{% load staticfiles %}`` musisz wstawić do każdego szablonu
    (w dowolnym miejscu), w którym chcesz odwoływać się do plików
    z katalogu :file:`static`.

.. figure:: img/czat23szabl.png

Na powyższym zrzucie widać wykonane ćwiczenie, czyli użycie dodatkowych
obrazków. Jednak strona nie wygląda dobrze, ponieważ treść podpowiedzi
nachodzi na logo Django (oczywiście przy małym rozmiarze okna przeglądarki).
Spróbujemy temu zaradzić.

Wykorzystamy prosty skrypt JQuery. Na początku ściągnij bibliotekę i skrypt
z podanego :download:`archiwum <js.zip>`. Rozpakuj pliki do katalogu
:file:`static/js`. Następnie do szablonu podstawowego :file:`baza.html`
dodaj przed tagiem zamykającym ``</body>`` kod:

.. raw:: html

    <div class="code_no">Plik baza.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: baza_z12.html
    :linenos:
    :lines: 39-40

Po odświeżeniu strony powinnieneś zobaczyć poprawioną stronę:

.. figure:: img/czat24szabl.png

cdn.

Materiały
***************

Słownik
================

.. include:: ../glossary.rst

1. O Django http://pl.wikipedia.org/wiki/Django_(informatyka)
2. Strona projektu Django https://www.djangoproject.com/
3. Co to jest framework? http://pl.wikipedia.org/wiki/Framework
4. Co nieco o HTTP i żądaniach GET i POST http://pl.wikipedia.org/wiki/Http

Źródła
===========

* :download:`czat_pr.zip <czat_pr.zip>`

Metryka
===============

:Autor: Robert Bednarz

:Utworzony: |date| o |time|

.. |date| date::
.. |time| date:: %H:%M

.. raw:: html

    <style>
        div.code_no { text-align: right; background: #e3e3e3; padding: 6px 12px; }
        div.highlight, div.highlight-python { margin-top: 0px; }
    </style>
