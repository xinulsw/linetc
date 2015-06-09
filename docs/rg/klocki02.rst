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
.. literalinclude:: rgkod12a.py
    :linenos:

Do zapamiętywania wybranych w rundzie pól posłużą funkcje ``ruszaj()``
i ``stoj()``:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod12b.py
    :linenos:

Ze zbioru ``bezpieczne`` wyłączamy wybrane pola i stosujemy nowe funkcje:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod12c.py
    :linenos:

.. raw:: html

    <hr />
