.. _bs:

Bootstrap
#############

`Bootstrap <https://getbootstrap.com>`_ to otwartoźródłowy zestaw narzędzi do
tworzenia responsywnych (zob.: :term:`responsywny`) stron WWW przy użyciu języków HTML, CSS i JS.
Framework ten dostarcza gotowych klas CSS i szablonów związanych z typografią,
formularzami, przyciskami, tabelami, oknami dialogowymi i innymi elementami.

Instalacja
==========

Instalacja w tym wypadku oznacza podłączenie arkuszy CSS i skryptów JS Bootstrapa
do kodu tworzonej strony. Najprościej skorzystać z zasobów przechowywanych w CDN-ach
(ang. content delivery network, rozproszony sieciowy system dostarczania treści).

Typowy szablon HTML 5 używający Bootstrapa wygląda następująco:

.. raw:: html

    <div class="code_no"><strong>index.html</strong> nr <script>var code_no1 = code_no1 || 1; document.write(code_no1++);</script></div>

.. highlight:: html
.. literalinclude:: index.html
    :linenos:
    :lineno-start: 1
    :lines: 1-
    :emphasize-lines: 9, 19, 22, 25

W zaznaczonych liniach dołączane są komponenty CSS i JS Bootstrapa.

.. note::
  Jeżeli korzystamy tylko z CSS-a i nie potrzebujemy komponentów JavaScript,
  skryptów JS nie musimy dołączać.

Układ strony
============

Do tworzenia układu strony używamy systemu siatkowego (ang. *grid system*). Wykorzystuje on
dwie klasy kontenerów:

* ``container`` – responsywny kontener o stałej szerokości z marginesami po lewej i prawej,
* ``container-fluid`` – kontener wykorzystujący całą dostępną szerokość

– oraz klasy definiujące podział na rzędy:

* ``row`` – definiuje rząd (wiersz) zawierający kolumny,
* ``col-`` – definuje kolumnę

–  i kolumny (maksymalna ilość kolumn w wierszu to 12).
Kolumny można grupować w zależności od rozdzielczości za pomocą odpowiednich klas:

* ``.col-`` – szerokość ekranu < 576px (extra small, xs),
* ``.col-sm-`` – szerokość => 576px (small devices, sm),
* ``.col-md-`` – szerokość => 768px (medium devices, md),
* ``.col-lg-`` – szerokość => 992px (large devices, lg),
* ``.col-xl-`` – szerokość => 1200px (xlarge devices, xl).

Przykładowy layout z dwoma równymi węższymi kolumnami bocznymi oraz kolumną środkową o szerokości
równej 50%, tj. 6 kolumnom z 12 dostępnych, od rozdzielczości >= 576px:

.. raw:: html

    <div class="code_no"><strong>layout.html</strong> nr <script>var code_no1 = code_no1 || 1; document.write(code_no1++);</script></div>

.. highlight:: html
.. literalinclude:: layout_ex1.html
    :linenos:
    :lineno-start: 1
    :lines: 1-

.. tip::

  Przetetuj powyższy kod. Zwróć uwagę, że w rozdzielczości poniżej 576px kolumny wyświetlane są jedna pod drugą,
  a w innych rozdzielczościach szerokość kolumn dostosowywana jest automatycznie.

Narzędzia Pokaż/ukryj
=====================

Schemat nazewnictwa klas zmieniających właściwość *display*:

* ``.d-{value}`` – dla xs
* ``.d-{breakpoint}-{value}`` – dla sm, md, lg i xl.

Możliwe wartości (ang. value): ``none, inline, inline-block, block, table, table-cell, table-row, flex, inline-flex``.

Przykłady:

* ``.d-block .d-sm-none`` – pokaż tylko na xs
* ``.d-none .d-lg-block .d-xl-none`` – pokaż tylko na lg
* ``.d-none .d-sm-block`` – ukryj tylko na xs
* ``.d-md-none .d-lg-block`` – ukryj tylko na md

Marginesy i wypełnienia
=======================

Schemat nazewnictwa klas zmieniających właściwości *margin* i *padding*:

* ``{property}{sides}-{size}`` – dla xs
* ``{property}{sides}-{breakpoint}-{size}`` - dla sm, md, lg, xl
* *property*: ``m`` – marginesy lub ``p`` – wypełnienie
* *sides*: ``t`` – góra, ``b`` – dół, ``l`` – lewo, ``r`` – prawo, ``x`` – lewo i prawo, ``y`` – góra i dół
* *sizes* – ``0`` – brak, ``1`` – 1/4 odstępu, ``2`` – 1/2 odstępu, ``3`` – pełny odstęp, ``4`` – półtora odstępu,
  ``5`` – potrójność odstępu, ``auto`` – odstęp automatyczny.

Przykłady:


Materiały
=========

1. `Dokumentacja Bootstrapa v.4 <https://getbootstrap.com/docs/4.0/getting-started/introduction/>`_;
2. `Podstawy flexbox <https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Flexible_Box_Layout/Basic_Concepts_of_Flexbox>`_ (Mozilla Developer Network);
3. `Przykłady flexbox <https://www.w3schools.com/cSS/css3_flexbox.asp>`_ (w3schools.com);
4. `Przykłady układów <https://getbootstrap.com/docs/4.0/examples/grid/>`_ (Bootstrap grid examples);