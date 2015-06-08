*Gra robotów* – klocki 2
####################################

Środowisko testowe przygotowujemy wg dokumentu :ref:`rgkit`.

Tworzenie sztucznej inteligencji robota można sprowadzić do odpowiedzi na
pytanie, według jakich zasad ma działać robot w określonych sytuacjach?
Na podstawie odpowiedzi określamy regułę zachowania, implementujemy ją
i testujemy, np.:

1) Co robot ma robić w sytuacji, gdy... i jaki priorytet ma mieć to działanie?
2) Odpowiedź, czyli reguła AI.
3) Jaki kod umożliwi robotowi realizowanie tej reguły?
4) Czy to działa?

Poniżej przedstawiamy kilka przykładów reguł i realizującego je kodu. Zadaniem
gracza jest odpowiedzieć, kiedy robot ma podjąć dane działanie i w jakiej kolejności.
Składając te "klocki", gracz tworzy strategię działania robota.

.. tip::

    * Każdy "klocek" można testować osobno, a później w połączeniu z innymi.
      Warto i trzeba zmieniać kolejność stosowanych reguł!
    * Kolejne wersje robota zapisujemy w osobnych plikach w katalogu :file:`robot`, np.:
      :file:`robot01.py`, :file:`robot02.py`, ...
    * Do "sparingów" :-) można wystawić robota przeciwko samemu sobie, przeciwko
      kolejnej wersji lub konfrontować go z botami open source.
    * Warto korzystać z symulatora!

.. code-block:: bash

    (env)~/robot$ rgrun robot01.py robot01.py
    (env)~/robot$ rgrun robot01.py robot02.py
    (env)~/robot$ rgrun bots/stupid26.py robot01.py

Aby rozpocząć, wydajemy w terminalu polecenia:

.. code-block:: bash

    ~$ cd robot
    ~/robot$ source env/bin/activate

.. raw:: html

    <hr />

Robot dotychczasowy
*******************

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot11.py
    :linenos:

Spróbujemy go ulepszyć!

Śledź wybrane miejsca
**********************

Aby unikać niepotrzebnych kolizji, nie należy wchodzić na wybrane wcześniej pola.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod12.py
    :linenos:

.. raw:: html

    <hr />
