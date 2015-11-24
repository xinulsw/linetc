.. _mvc:

Model – Widok – Kontroler
#########################

Wzorzec projektowania aplikacji M(odel)V(iew)C(ontroller),
czyli Model–Widok–Kontroler [#]_, pozwala na oddzielenie danych od ich prezentacji oraz logiki aplikacji.
Funkcje kolejnych elementów są następujące:

* Modele – :term:`model` w Django reprezentuje źródło informacji;
  są to klasy Pythona odwzorowujące pojedyncze tabele w bazie danych [#]_;
  każda klasa zawiera właściwości odpowiadające polom tabeli,
  może też zawierać funkcje wykonujące operacje na danych.
  Instancja takiej klasy odpowiada rekordowi danych.
  Modele definiujemy w pliku :file:`models.py`.

* Widoki – :term:`widok` w Django to funkcja czy klasa Pythona, która na podstawie żądań www
  (dla danych adresów URL) zwraca odpowiedź, najczęściej w postaci kodu HTML
  generowanego w szablonach (templates); odpowiedzią może być również
  przekierowanie na inny adres, jakiś dokument lub obrazek.
  Django zawiera wiele widoków wbudowanych. Widoki modyfikujemy
  lub definiujemy w pliku :file:`views.py`.

* Kontroler – :term:`kontroler` to mechanizm kierujący kolejne żądania
  do odpowiednich widoków na podstawie wzorców adresów URL zawartych w pliku :file:`urls.py`.

.. [#] Twórcy Django traktują jednak ten wzorzec elastycznie, mówiąc że ich
   framework wykorzystuje wzorzec MTV, czyli model (model), szablon (template), widok (view).
.. [#] Takie odwzorowanie nosi nazwę mapowania obiektowo-relacyjnego (ORM).
   ORM odwzorowuje strukturę bazy na obiekty Pythona.