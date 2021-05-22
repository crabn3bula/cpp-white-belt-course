# Задание по программированию: Автобусные остановки — 1

#### Инструкции:
Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

* __NEW_BUS *bus stop_count stop1 stop2 ...*__ — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
* __BUSES_FOR_STOP *stop*__ — вывести названия всех маршрутов автобуса, проходящих через остановку *stop*.
* __STOPS_FOR_BUS *bus*__ — вывести названия всех остановок маршрута *bus* со списком автобусов, на которые можно пересесть на каждой из остановок.
* __ALL_BUSES__ — вывести список всех маршрутов с остановками.

#### Формат ввода:
В первой строке ввода содержится количество запросов *Q*, затем в *Q* строках следуют описания запросов.

Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

Для каждого запроса __NEW_BUS *bus stop_count stop1 stop2 ...*__ гарантируется, что маршрут *bus* отсутствует, количество остановок больше 0, а после числа *stop_count* следует именно такое количество названий остановок, причём все названия в каждом списке различны.

#### Формат вывода:
Для каждого запроса, кроме __NEW_BUS__, выведите соответствующий ответ на него:

* На запрос __BUSES_FOR_STOP *stop*__ выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами __NEW_BUS__. Если остановка *stop* не существует, выведите __No stop__.
* На запрос __STOPS_FOR_BUS *bus*__ выведите описания остановок маршрута *bus* в отдельных строках в том порядке, в котором они были заданы в соответствующей команде __NEW_BUS__. Описание каждой остановки *stop* должно иметь вид __*Stop stop: bus1 bus2 ...*__, где __*bus1 bus2 ...*__ — список автобусов, проезжающих через остановку *stop*, в порядке, в котором они создавались командами __NEW_BUS__, за исключением исходного маршрута *bus*. Если через остановку *stop* не проезжает ни один автобус, кроме *bus*, вместо списка автобусов для неё выведите __no interchange__. Если маршрут *bus* не существует, выведите __No bus__.
* На запрос __ALL_BUSES__ выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута bus должно иметь вид __*Bus bus: stop1 stop2 ...*__, где __*stop1 stop2 ...*__ — список остановок автобуса *bus* в порядке, в котором они были заданы в соответствующей команде __NEW_BUS__. Если автобусы отсутствуют, выведите __No buses__.


#### Предупреждение
Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили ни одной, перечитайте условие ещё раз.

#### Пример:
Ввод
```
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES
```

Вывод
```
No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
```