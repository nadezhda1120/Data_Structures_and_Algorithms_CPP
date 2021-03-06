```
github.com/andy489
```
*Пример:*

Примерен вход|Очакван изход
-|-
11<br>
3 7 8 2 15 10 7 1 14 12 3|24

Задачата може да се перифразира като се опитаме да намерим максималното лице на правоъгълник заключено в хистограма.

Създаваме празен стек, който ще съдържа позиции на данните. Започваме от първата данна и за всяка данна проверяваме дали стека е празен или големината на текущата данна не е по-малка от големината на данната на позицията, която е на върха на стека. Ако това е изпълнено, вкарваме текущата позиция в стека и я инкрементираме, в противен случай (т.е. текущата данна е с по малка стойност от тази с позиция на върха на стека или стека е бил празен) запаметяваме позицията на върха на стека и я премахваме от стека.<br>Изчисляваме текущото лице, което е равно на стойността на данната на позиция премахнатия връх на стека (приемаме като текущ минимум най-високата до момента данна на стека) умножаваме по текущата позиция, ако стека е празен или текущата позиция минус запаметената позиция от върха на стека минус единица, в противен случай.<br>Актуализираме максималното лице, ако е необходимо.<br>
Сега в стека са останали само тези позиции, чиито данни не са имали по-малки по стойност данни след тях. Следователно докато има останали позициив стека, за всяка една от тях последователно трябва да пресметнем текущото лице по аналогичен на горния начин и да го актуализираме ако е необходимо (съобразяваме, че последната позиция в стека ще е на данната с най-малка стойност).
