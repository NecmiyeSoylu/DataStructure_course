## Binary Search Tree
Nedir bu ikili arama ağacı. ağaç dediğimiz yapı birbirine bağlı ağaç dallarına andıran yapıdadır. dairesel olamaz, tek yönlüdür. 
ikili demek her düğümün en fazla iki çocuğu olabilir demek. 
search tree yani arama ağacı dediğimiz zaman, küçüklük büyüklük ilşkiisne göre bir sıralama söz konusudur. 
düğüme ekeleme yapılırken kendinden küçük değerler soluna, büyük değerler sağına atanır. Bu yüzden bir binary search tree ye atama 
yapma sırasıda önemlidir. atama sırasını değiştirdikçe farlı ağaçalr elde edilir.
heap=yükseklik bulunduğu yerden root'a kadarki dallar(çubuklar). o seviyedeki max elemam sayısı 2^heap olur
leaf=yaprak yani çocoksuz düğümler
root= kök en baştaki düğüm

binary tree de sayma ekleme yaparken her zaman rekurssif kullanırız. çünkü her seferinde hem sağa hem sola bakabilmek için döngüye ihtiyaç olur.