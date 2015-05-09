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

Idź do środka planszy
**********************

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod01.py
   :linenos:

.. raw:: html

    <hr />

Broń się, gdy jesteś w środku
******************************

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod02.py
    :linenos:

.. raw:: html

    <hr />

Atakuj przeciwników, jeśli są obok
***********************************

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
ułatwiają definiowanie zachowań robotów. Zobacz dalsze przykłady.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgzbiory.py
    :linenos:

.. raw:: html

    <hr />

Atakuj przeciwników, jeśli są obok
***********************************

Wersja wykorzystująca zbiory pól.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod04.py
    :linenos:

.. raw:: html

    <hr />

Atakuj, jeśli nie grozi ci śmierć
***********************************

Wersja wykorzystująca zbiory pól.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod05.py
    :linenos:

.. raw:: html

    <hr />
