multi_modul_arduino

Модуль управления и индикации на ардуино-платформе.
Имеет в своем составе 4 кнопки управления, индикацию на LCD Nokia 1202, 
шину управления SPI и I2C, 2-а аналоговых входа, один вход прерываний и несколько цифровых входов.
Библиотека для LCD Nokia 1202 https://github.com/SerPanRC/LCD_Nokia1202_Arduino.git

Атмега включена без внешнего кварцевого резонатора, используется внутренний генератор 8мгц. Для работы в ардуино необходимо в файл
arduino-1.X.X\hardware\arduino\boards.txt вставить следующие строки-

##############################################################

micro168pa.name= (3.3V, 8 int MHz) w/ ATmega168PA

micro168pa.upload.protocol=stk500
micro168pa.upload.maximum_size=14336
micro168pa.upload.speed=19200

micro168pa.bootloader.low_fuses=0xE2
micro168pa.bootloader.high_fuses=0xdd
micro168pa.bootloader.extended_fuses=0x00
micro168pa.bootloader.path=atmega
micro168pa.bootloader.file=ATmegaBOOT_168_pro_8MHz.hex
micro168pa.bootloader.unlock_bits=0x3F
micro168pa.bootloader.lock_bits=0x0F

micro168pa.build.mcu=atmega168p
micro168pa.build.f_cpu=8000000L
micro168pa.build.core=arduino

После этого появится в меню выбора плат (3.3V, 8 int MHz) w/ ATmega168PA , ее и выбираем и для прошивки загрузчика и при загрузке скретча.
Пример измененного файла boards.txt есть в каталоге.

В текущей папке представлен внешний вид модуля, файл печатной платы, схема модуля.
В папке receiver_1_2Ghz представлены файлы для проекта приемника 
на диапазон 0,8-1,45Ghz c использованием модуля.

