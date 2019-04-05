Задача 1. Напишете функция mypow n k​, която повдига n на степен k. Същото като n ^ k, което разбира се, не може да използвате.

Задача 2. Напишете функция mysumpow k xs​, която взима число k и списък xs и връща сумата x0 ^ k + x1 ^ k + .. + xN ^ k. Напишете функцията по два начина:
	а) рекурсивно, наименувайте функцията mysumpow_rec
	б) използвайки функцията sum и "list comprehension", наименувайте функциата mysumpow_lc

Задача 3. Напишете функция mytake n xs​, която връща първите n елемента на списъка xs. Ако n > length xs, функцията връща целия списък. Не може да използвате функцията take, която прави точно това.
	Пример: ​
		mytake 3 [1 .. 10] = [1, 2, 3]

Задача 4. Напишете функция myreverse xs​, която обръща списъка xs. Не може да използвате функцията reverse, която прави точно това.
	Пример: ​
		myreverse [1, 2, 3] = [3, 2, 1]

Задача 5. Напишете функция myprimefactors n >= 2​, която връща списък с простите множители на n,
подредени в нарастващ ред.
	Пример:
		myprimefactors 20 = [2, 2, 5], because 20 = 2 * 2 * 5
		myprimefactors 1 = []

Задача 6. Напишете функция mysentences subjects verbs objects​, която връща списък с всички изречения от вида subject verb object (SVO), където:
­ - subject e елемент на списъка subjects,
­ - verb е елемент на списъка verbs,
­ - object e елемент на списъка objects.
	Пример: ​
		mysentences ["Sam", "Mary"] ["loves", "hates"] ["apples", "dogs"] =
		[
		"Sam loves apples", "Sam loves dogs", "Sam hates apples", "Sam hates dogs",
		"Mary loves apples", "Mary loves dogs", "Mary hates apples", "Mary hates dogs"
		]
