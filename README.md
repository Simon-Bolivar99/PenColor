# PenColor
PenColor - виджет для выбора стиля QPen , цвета и толщины линии. 
## Информация о виджите
Виджет состоит из:
-  QSpinBox - выбор толщины линии
-  ColorToolButton - выбор цвета (описание виджета по ссылке: https://github.com/Simon-Bolivar99/ColorToolButton)
-  ComboLineBox - выбор стиля линии (виджет на основе QComboBox)
-  CustomDelegate - делегат для отображения линий 

![Иллюстрация к проекту](https://github.com/Simon-Bolivar99/PenColor/blob/master/screen/menu.png)

## Исходные файлы
- *ColorToolButton.h* - виджет кнопки для выбора цвета
- *PenColor.h*        - исходный код главного виджета
- *MainWindow.cpp*    - окно для отображения виджета
- *CustomDelegate*    - реализация делегата для работы с ComboLineBox
- *ComboLineBox*      - QComboBox с отрисовкой линий на виджете 

## Основные функции
- getColor() - текущий цвет
- getLine()  - текущий стиль линии
- getThick() - текущаяя толщина линии
