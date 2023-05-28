IDBConnection.h - интерфейс описывающий подключение к базе данных
DBConnection.h - класс, реализующий интерфейс IDBConnection.h. 
MockDBConection.h - mok-класс для тестирования интерфейса IDBConnection.h
Tester.h - для проверки работы MockDBConection.h
classThatUseDB.h - для работы с базой данных, через объекты, реализующие интерфейс IDBConnection.h
Программа выполняет 3 теста:
- test1 тестирует мок-объект через объект класса Tester
- test2 тестирует мок-объект через объект класса classThatUseDB
- test3 тестирует работу методов класса classThatUseDB и DBConnection
