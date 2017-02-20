GetSimple CMS
#############

GetSimple jest przykładem popularnych od dłuższego czasu systemu zarządzania
treścią (ang. *Content Management System*, :term:`CMS`). Zadaniem CMS-ów jest
wspomaganie tworzenia serisów intenetowych WWW i wspomaganie zarządzania nimi przy wykorzystaniu
przyjaznych dla użytkownika interfejsów, dzięki czemu nie musi on być
specjalistą od wspomnianych na wstępie technologii WWW.
Inne przykłady popularnych CMS-ów to: `Drupal <http://pl.wikipedia.org/wiki/Drupal>`_,
`Joomla! <http://pl.wikipedia.org/wiki/Joomla!>`_ czy `WordPress <http://pl.wikipedia.org/wiki/WordPress>`_.

Pobranie archwium
*****************

.. note::

    GetSimple wymaga działającego serwera WWW, przy czym serwery bazodanowe
    typu MySQL itp. nie są koniecznie, ponieważ GS przechowuje pliki w formacie
    ``XML``. Zob. materiał :ref:`Serwer deweloperski WWW <lwamp>`.

Najnowszą wersję GS pobieramy ze strony `Download GetSimple CMS <http://get-simple.info/download>`_
lub z :download:`od nas <GetSimpleCMS-3.3.13.zip>`.
Ściągnięte archiwum ``zip`` umieszczamy w podkatalogu ``public_html`` katalogu domowego
użytkownika Linuksa lub w podkatalogu ``www`` folderu instalacyjnego ``UwAmp``.
Rozpakowujemy je, a następnie nazwę utworzonego katalogu zmieniamy na ``gs``.

.. warning::

    W środowisku Linux folderowi ``gs`` musimy nadać uprawnienia do zapisu
    i odczytu nie tylko dla właściciela, ale i dla grupy oraz innych.
    Robimy to z poziomu menedżera plików po kliknięciu prawym klawiszem
    myszy nazwy katalogu i wybraniu "Właściwości/Uprawnienia" (zob. zrzut poniżej).
    Uwaga: na pytanie typu "Zastosować rekursywnie" odpowiadamy twierdząco.
    Można też w katalogu ``public_html`` wydać polecenie w terminalu ``chmod -R 777 gs``.

.. figure:: img/gs01.jpg


Instalacja
**********

Następnie przechodzimy do przeglądarki i rozpoczynamy instalację wpisując w polu adresu:
``http://localhost/~nazwa_użytkownika/gs/admin`` (Linux)
lub ``http://localhost/gs/admin`` (Windows).
Jeżeli skorzystałeś z udostępnionego przez nas archiwum GetSimple,
na stronie instalacyjnej możesz od razu wybrać język polski. Później
klikamy "Continue with Setup" ("Kontynuuj instalację").

.. figure:: img/gs02.jpg

.. note::

    W środowisku Linux ewentualne błędy ``chmod`` ignorujemy.

Na następnej stronie wpisujemy nazwę strony, login i email administratora.

.. figure:: img/gs03.jpg

Po naciśnięciu "Install Now!" ("Instaluj") może zostać wyświetlona strona z błędem ze względu
na brak możliwości wysłania wiadomości e-mail z danymi logowania. To normalne.
Wyświetlone hasło możemy ewentualnie skopiować, po czym kilkamy link "login here".

.. figure:: img/gs04.jpg

Spolszczenie
************

Jeżeli jest taka potrzeba, plik spolszczenia pobieramy ze strony
`Extend <http://get-simple.info/extend/>`_, na której wyszukujemy w polu
"Serach Repository" hasło "polish" i wybieramy link do ostatniej wersji:

.. figure:: img/gs05.jpg


Spolszczenie możemy również pobrać
:download:`od nas <polish-language-spolszczenie-gs-3.3.zip>`.
Ściągnięte archiwum przenosimy do folderu ``gs/admin/lang`` i tam rozpakowujemy.

.. figure:: img/gs06.jpg


Konfiguracja
*************

Wracamy do panelu administracyjnego w przeglądarce (``http://localhost/~nazwa_użytkownika/gs/admin``),
w razie potrzeby odświeżamy stronę naciskając :kbd:`F5` i wybieramy w prawym górnym rogu **Settings** (**Ustawienia**).
Ustawiamy: strefę czasową ("Local Timezone"), język interfejsu admina ("Language") oraz
nowe hasło ("New Password") – i klikamy "Save settings".

.. figure:: img/gs07.jpg


Wtyczki
*******

Jak większość CMS-ów, GetSimple oferuje mechanizm wtyczek, pozwalający rozszerzać
w miarę potrzeb funkcjonalność zarówno od strony użytkownika, jak i administratora.
Instalacja wtyczek polega na pobraniu ich ze strony `Extend Repository <http://get-simple.info/extend/>`_,
a następnie rozpakowaniu archiwum ``zip`` w podfolderze ``gs/plugins``.

Pakiet przykładowych wtyczek można pobrać :download:`od nas <plugins.zip>` lub pojedynczo:

* `I18N <http://get-simple.info/extend/plugin/i18n/69/>`_ – dodaje wsparcie
  dla stron w różnych językach oraz bardzo użyteczne hierarchiczne menu;
* `I18N Gallery <http://get-simple.info/extend/plugin/i18n-gallery/160/>`_
  – dodaje możliwość wygodnego tworzenia galerii zdjęć i umieszczania ich
  na stronach;
* `DynPages <http://get-simple.info/extend/plugin/dynpages/81/>`_  – możliwość umieszczania
  na stronach kodu generowanego przez komponenty php;
* `I18N Search <http://get-simple.info/extend/plugin/i18n-search/82/>`_
  – umożliwia m. in. wyszukiwanie tekstu na stronach serwisu, ale również
  tworzenie list zasobów oznaczonych tymi samymi tagami;
* `I18N Special Pages <http://get-simple.info/extend/plugin/i18n-special-pages/319/>`_
  – pozwala tworzyć strony specjalne typu newsy, artykuły, karty produktów
  itp.

Zawartość przykładowego folderu ``plugins`` powinna wyglądać następująco:

.. figure:: img/gs08.jpg


.. note::

    W Linuksie po umieszczeniu archiwów zip w podkatalogu ``gs/plugins``
    wygodnie je rozpakujesz wydając w terminalu polecenie typu:
    ``unzip nazwa_archiwum.zip``.

    Użycie polecenia "Rozpakuj tutaj" w menedżerze plików może umieścić pliki
    w dodatkowym i niepotrzebnym podfolderze, z którego trzeba je będzie przenieść
    do folderu nadrzędnego (``plugins``).


Wtyczkami zarządzamy w sekcji "Wtyczki" panelu administracyjnego. Tam można
je m. in. włączać lub wyłączać.

.. figure:: img/gs09.jpg


Strona główna
*************

Domyślnie dodana zostanie demonstracyjna strona główna widoczna w panelu "Strony",
którą wyświetlimy w przeglądarce, jeżeli klikniemy nazwę serwisu w panelu administracyjnym
lub wpiszemy ``http://localhost/~nazwa_użytkownika/gs/`` (Linux) lub ``http://localhost/gs/`` (Windows)
w polu adresu.

.. figure:: img/gs10.jpg


Materiały
**************

1. `GetSimple`_
2. `GetSimple – dodatki`_

.. _GetSimple: http://get-simple.info/
.. _GetSimple – dodatki: http://get-simple.info/extend/
