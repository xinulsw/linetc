Adresy (Qt5)
============================

Niniejszy scenariusz pokazuje, jak zacząć pracę w środowisku IDE Qt Creator
przy wykorzystaniu biblioteki Qt w wersji 5.

Nowy projekt
---------------------------

Po uruchomieniu aplikacji Qt Creator wybieramy przycisk "New Project",
który uruchamia kreatora aplikacji.

W pierwszym oknie "Applications" i "Qt Widget Applications", co
oznacza, że chcemy utworzyć program z interfejsem graficznym oparty
na klasie QWidget. W następnym oknie podajemy nazwę projektu,
np, "adresy", oraz wskazujemy ścieżkę do katalogu, w którym
będą zapisywane pliki wchodzące w skład projektu.
W następnym oknie wybieramy tzw. "kit", czyli zestaw definiujący
docelowe środowisko, kompilator itp. ustawienia. Dostępne
zestawy muszą być wcześniej określone w ustawieniach Qt Creatora

Kolejne okno pozwala definiować nazwę klasy głównej i klasę podstawową,
podajemy "adresy" i wybieramy "QWidget". W następnym ostatnim oknie
niczego nie zmieniamy, kończymy kliknięciem przycisku "Finish".

Efektem działania kreatora będzie utworzenie następujących plików:

    1) ``adresy.h`` - tutaj będziemy deklarować wszystkie używane w programie
    obiekty (elementy interfejsu), a także publiczne sloty, czyli funkcje
    powiązanie z określonymi sygnałami (zdarzeniami).

    2) ``adresy.cpp`` - tu znajdzie się kod tworzący obiekty interfejsu, łączący
    sygnały ze slotami, a wreszcie implementacja slotów.

    3) ``main.cpp`` - plik, w którym tworzona i uruchamiana jest instancja naszej
    aplikacji.

    4) ``adresy.ui`` - jak wskazuje rozszerzenie ("ui" - ang. user interface),
    plik zawierać będzie opis graficznego interfejsu aplikacji zapisany
    za pomocą znaczników XML.

Tworzenie interfejsu
------------------------

Zaczniemy od utworzenia głównego okna naszej aplikacji. W tym celu
dwa razy klikamy plik adresy.ui i przechodzimy do tworzenia
formularza. 

Na początku klikamy obiekt "Grid Layout" z kategorii "Layouts" i rysujemy prostokąt na
formularzu tak, aby nie wypełniał go w całości. Dodana kontrolka
umożliwia porządkowanie innych elementów tworzących interfejs w prostokątnej
siatce. Dalej dodamy dwie etykiety, czyli obiekty "Label" z kategorii
"Display Widgets". Staramy się je umieścić jedna nad drugą w dodanej przed
chwilą siatce.

.. tip::

    Po wybraniu obiektu i najechaniu na *Grid Layout* należy obserwować
    niebieskie podświetlenia, które pojawiają się w pionie i poziomie,
    wskazują one, gdzie umiesczony zostanie dodawany obiekt.
