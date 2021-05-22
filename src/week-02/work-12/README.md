# Тренировочное задание по программированию: Справочник столиц

#### Инструкции:
Реализуйте справочник столиц стран.

На вход программе поступают следующие запросы:

* __CHANGE_CAPITAL *country new_capital*__ — изменение столицы страны country на __*new_capital*__, либо добавление такой страны с такой столицей, если раньше её не было.
* __RENAME *old_country_name new_country_name*__ — переименование страны из __*old_country_name*__ в __*new_country_name*__.
* __ABOUT *country*__ — вывод столицы страны __*country*__.
* __DUMP__ — вывод столиц всех стран.

#### Формат ввода:
В первой строке содержится количество запросов *Q*, в следующих *Q* строках — описания запросов. Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

#### Формат вывода:
Выведите результат обработки каждого запроса:

В ответ на запрос CHANGE_CAPITAL country new_capital выведите
* __Introduce new country *country* with capital *new_capital*__, если страны country раньше не существовало;
* __Country *country* hasn't changed its capital__, если страна __*country*__ до текущего момента имела столицу __*new_capital*__;
* __Country *country* has changed its capital from *old_capital*__ *to* __*new_capital*__, если страна __*country*__ до текущего момента имела столицу __*old_capital*__, название которой не совпадает с названием __*new_capital*__.

В ответ на запрос __RENAME *old_country_name new_country_name*__ выведите
* __Incorrect rename, skip__, если новое название страны совпадает со старым, страна __*old_country_name*__ не существует или страна __*new_country_name*__ уже существует;
* __Country *old_country_name* with capital *capital* has been renamed to *new_country_name*__, если запрос корректен и страна имеет столицу __*capital*__.

В ответ на запрос __ABOUT *country*__ выведите
* __Country *country* doesn't exist__, если страны с названием __*country*__ не существует;
* __Country *country* has capital *capital*__, если страна __*country*__ существует и имеет столицу __*capital*__.

В ответ на запрос __DUMP__ выведите
* __There are no countries in the world__, если пока не было добавлено ни одной страны;
* последовательность пар вида __*country/capital*__, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна. При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.

#### Пример 1:
Ввод
```
6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP
```

Вывод
```
Introduce new country RussianEmpire with capital Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic has capital Petrograd
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
USSR/Moscow
```

#### Пример 2:
Ввод
```
24
RENAME FakeCountry FarFarAway
ABOUT FarFarAway
DUMP
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL ColonialBrazil Salvador
CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
RENAME TsardomOfRussia RussianEmpire
CHANGE_CAPITAL RussianEmpire Moscow
CHANGE_CAPITAL RussianEmpire SaintPetersburg
CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
DUMP
RENAME ColonialBrazil EmpireOfBrazil
ABOUT RussianEmpire
RENAME EmpireOfBrazil UnitedStatesOfBrazil
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
ABOUT RussianEmpire
DUMP
RENAME USSR USSR
```

Вывод
```
Incorrect rename, skip
Country FarFarAway doesn't exist
There are no countries in the world
Introduce new country TsardomOfRussia with capital Moscow
Country TsardomOfRussia hasn't changed its capital
Introduce new country ColonialBrazil with capital Salvador
Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
Country RussianEmpire has capital SaintPetersburg
Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
Country RussianEmpire doesn't exist
FederativeRepublicOfBrazil/Brasilia USSR/Moscow
Incorrect rename, skip
```

#### Пример 3:
Ввод
```
10
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME USSR RussianEmpire
DUMP
ABOUT USSR
DUMP
RENAME RussianEmpire RussianEmpire
DUMP
CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
RENAME RussianEmpire UnitedStatesOfBrazil
DUMP
```

Вывод
```
Introduce new country RussianEmpire with capital Petrograd
Incorrect rename, skip
RussianEmpire/Petrograd
Country USSR doesn't exist
RussianEmpire/Petrograd
Incorrect rename, skip
RussianEmpire/Petrograd
Introduce new country UnitedStatesOfBrazil with capital Brasilia
Incorrect rename, skip
RussianEmpire/Petrograd UnitedStatesOfBrazil/Brasilia
```