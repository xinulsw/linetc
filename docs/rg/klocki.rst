*Gra robotów* – klocki
####################################

Tworzenie sztucznej inteligencji robota można, upraszczając, sprowadzić do
stawiania pytań, określania zasad zachowania, implementowania kodu
i testowania, np.:

1) Co robot ma robić w sytuacji, gdy... i jaki priorytet ma mieć to działanie?
2) Odpowiedź, czyli reguła AI.
3) Jaki kod umożliwi robotowi realizowanie tej reguły?
4) Czy to działa?

Poniżej przedstawiamy kilka reguł i realizującego je kodu. Zadaniem gracza
jest odpowiedzieć, kiedy robot ma podjąć dane działanie i w jakiej kolejności.
Składając te "klocki", gracz tworzy logikę działania robota.

.. tip::

    Każdy klocek można testować osobno, a później w połączeniu z innymi.
    Do "sparingów" :-) można wystawić robota przeciwko samemu sobie lub
    konfrontować go z botami open source:

.. code-block:: bash

    (env)~/robot$ rgrun robot01.py robot01.py
    (env)~/robot$ rgrun bots/stupid26.py robot01.py

Idź do środka
**************

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod01.py
   :linenos:

.. raw:: html

    <hr />

Broń się w środku
********************

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod02.py
    :linenos:

.. raw:: html

    <hr />

Atakuj obok
**************************

Wersja wykorzystująca pętlę.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod03.py
    :linenos:

.. raw:: html

    <hr />

Zbiory pól
****************

Poniższy kod definiuje zbiory zawierające pola różnej kategorii, które
ułatwiają wyznaczanie zachowań robotów. Zobacz dalsze przykłady.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgzbiory.py
    :linenos:

.. raw:: html

    <hr />

Opuść wejście
**********************

Wersja wykorzystująca zbiory pól.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod04.py
    :linenos:

.. raw:: html

    <hr />

Atakuj obok
**************************

Wersja wykorzystująca zbiory pól.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod05.py
    :linenos:

.. raw:: html

    <hr />

Atakuj, jeśli nie umrzesz
***********************************

Wersja wykorzystująca zbiory pól.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod06.py
    :linenos:

.. raw:: html

    <hr />

Atakuj na 2 kroki
**************************

Wersja wykorzystująca zbiory pól.
Jeżeli w odległości 2 kroków jest przeciwnik, atakuj.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod07.py
    :linenos:

.. raw:: html

    <hr />

Bezpieczne pola
****************

Wersja wykorzystująca zbiory pól.
Zbiór sąsiednich pól, na które można wejść bez ryzyka.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod08.py
    :linenos:

.. raw:: html

    <hr />

Najbliżej do celu
*******************

Wersja wykorzystująca zbiory pól.
Funkcja, która z podanego zbioru pól (bots) zwraca pole, na które należy wejść,
aby najszybciej dostać się do celu (loc), np. środka planszy lub wroga.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod09.py
    :linenos:

.. raw:: html

    <hr />

Bezpiecznie do środka
**************************

Wersja wykorzystująca zbiory pól.
Idź z punktu wejścia bezpiecznie do środka.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod10.py
    :linenos:

.. raw:: html

    <hr />

Najbliższy wróg
*****************

Wersja wykorzystująca zbiory. Idź bezpiecznie w kierunku najbliższego wroga.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod11.py
    :linenos:

Śledź wybrane miejsca
**********************

Aby unikać niepotrzebnych kolizji, nie należy wchodzić na wybrane wcześniej
pola.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod12.py
    :linenos:

.. raw:: html

    <hr />
