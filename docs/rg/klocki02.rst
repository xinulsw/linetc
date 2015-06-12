*Gra robotów* – klocki 2
####################################

Robot dotychczasowy
*******************

W pierwszej części klocków stworzyliśmy takiego robota:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot11.py
    :linenos:

Jego działanie opiera się na zbiorach pól określonego typu i następujących
regułach:

#. jeżeli nie ma nic lepszego, broń się
#. z punktu wejścia idź bezpiecznie do środka;
#. atakuj wrogów wokół siebie, o ile to bezpieczne, jeżeli nie,
   idź bezpiecznie do środka;
#. atakuj wrogów dwa pola obok;
#. idź bezpiecznie na wroga

Spróbujemy go ulepszyć!

Śledź wybrane miejsca
**********************

Aby unikać niepotrzebnych kolizji, nie należy wchodzić na wybrane wcześniej pola.
Na początku definiujemy dwie zmienne globalne i inicjujemy dane:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod22a.py
    :linenos:

Do zapamiętywania wybranych w rundzie pól posłużą funkcje ``ruszaj()``
i ``stoj()``:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod22b.py
    :linenos:

Ze zbioru ``bezpieczne`` wyłączamy wybrane pola i stosujemy nowe funkcje:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod22c.py
    :linenos:

.. raw:: html

    <hr />

.. tip::

    Można zapamiętywać wszystkie wybrane ruchy lub tylko niektóre. Przetestuj,
    czy ma to wpływ na skuteczność AI.

Atakuj najsłabszego
********************

Do tej pory atakowaliśmy przypadkowego robota wokół nas, lepiej wybrać
najsłabszego.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod23.py
    :linenos:

Funkcja ``minhp()`` zwróci nam położenie najsłabszego wroga. Argument
parametru ``key``, czyli wyrażenie :ref:`lambda <lambda>` wskazuje cechę
robotów, wg której są porównywane.

.. raw:: html

    <hr />

Samobójstwo lepsze niż śmierć?
******************************

Jeżeli grozi nam śmierć, a nie ma bezpiecznego miejsca, aby uciec, lepiej
popełnić samobójstwo:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod24.py
    :linenos:

Unikaj nierównych starć
************************

Nie warto walczyć z przeważającą liczbą wrogów. Regułę tę można dodać
na kilka sposobów, np.:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod25.py
    :linenos:
