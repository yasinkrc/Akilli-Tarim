# Akilli-Tarim
1. TANIMLAMA
Bu ödevde Akıllı Tarım isimli zirai gübreleme ve ilaçlama simülasyonunun arka planında yapılması 
istenen işlemleri belli kurallar dâhilinde gerçekleştiren C++ kodunu yazmanız gerekmektedir. Kodu 
yazarken heap (öncelikli kuyruk) ve graf veri yapısı kullanılacaktır. Ayrıca ihtiyaç dâhilinde diğer veri 
yapılarını da kullanabilirsiniz. (C++ dilinde hazır STL kütüphaneleri kullanılmayacaktır.)
Akıllı Tarım isimli simülasyonun senaryosu aşağıdaki şekildedir:
Bu simülasyonda bir çiftçinin 6 adet tarlası bulunmaktadır. Çiftçi akıllı traktörü ile arazisine ekmiş 
olduğu 6 farklı tarlanın ihtiyaçlarını (sulama, ilaçlama, gübreleme, çapalama) en kısa yolu takip ederek 
karşılamak istemektedir. Bu sayede hem maliyet hem zaman tasarrufu yaparak çevre dostu zirai 
faaliyetler yapmayı amaçlamaktadır.

Akıllı Tarım isimli simülasyonda yapılacaklar:
Tarlayı Tara: Akıllı traktör tarla üzerinde başlangıç noktasından tüm tarlayı gezerek ihtiyaçları 
belirler. Bu tarama sırasında hangi tarlanın neye ihtiyacı olduğunu belirleyebilir. Akıllı traktör, 
tarlaların önceliklerine göre bir sıralama yapar.
İhtiyaç Karşıla: Akıllı traktör, bu sıraya göre tarlalara girer ve sulama, gübreleme, ilaçlama, 
çapalama işlemlerini yapa

2. PROBLEM
Akıllı Traktör
o Sulama, ilaçlama, çapalama ve gübreleme işlemlerini yapabilmektedir.
o Her bir işleme özel aparatı bulunmaktadır.
o İşlemlerin bir öncelik sıralaması şu şekildedir: İlaçlama > Çapalama > Gübreleme > Sulama.
Akıllı Tarım isimli simülasyon iki bölümden oluşmaktadır. 
Tarlayı Tara bölümünde akıllı traktör mevcut konumundan hareket eder ve tarlaların en öncelikli işlemi 
için bir sıralama belirler.
İhtiyaç karşıla bölümünde ise akıllı traktör belirlediği sıraya göre ilk olarak ihtiyacını karşılayacağı 
tarlaya gider ve tarlanın sadece o anki belirlenen ihtiyacını karşılar. Örneğin bir tarlanın birden fazla 
ihtiyacı olabilir ancak traktör ilk işlem (ilaçlama) için taktığı aparatı ile tüm tarlaların ilaçlama işlemini 
bitirmeden bulunduğu tarladaki diğer işlemlere geçmez. Takılan aparat ile tüm tarlaların işlemi 
bittiğinde bulunduğu konumdan başlayarak bir sonraki işlem için en kısa yolları takip ederek ihtiyaçları 
karşılar. Traktör tüm tarlaların tüm işlemleri karşılanana kadar çalışmaya devam eder.
Problem adımları:
1. Tarlaların numarası Tablo 1’de verilmiştir. 
Örneğin 1 numaralı tarla domates, 2 numaralı tarla biber tarlasını vb. temsil eder.
2. Tarlaların hangi işlemlere ihtiyaç duyduğu bilgisi Tablo 2’de verilmiştir. Tabloya göre 
“1”ler tarlanın ilgili işleme ihtiyacı olduğunu, “0”lar tarlanın ilgili işleme ihtiyacının 
olmadığını temsil etmektedir.
Örneğin; 1 numaralı tarlanın (domates) ihtiyaçları sulama, gübreleme, çapalama olup 
ilaçlamaya ihtiyaç duymamaktadır. 
2 numaralı tarlanın (biber) ihtiyaçları sulama, ilaçlama olup; gübreleme ve çapalamaya 
ihtiyaç duymamaktadır.
3. Traktör 4 farklı işlemi (sulama, ilaçlama, gübreleme, çapalama) de ihtiyaçlar dâhilinde 
karşılayabilmektedir.
4. Akıllı traktör 1 numaralı tarladan başlayacak şekilde ilk öncelikli işlem (İlaçlama) için en 
kısa rotayı oluşturur. Bu rotayı takip ederek tüm tarlaların ilk öncelikli işlemi tamamlanır.
5. Daha sonra bulunduğu tarladan başlayacak şekilde ikinci öncelikli işlem (Çapalama) için en 
kısa rotayı belirler ve yine tüm tarlaların işlemlerini tamamlar. 
6. Traktör tüm tarlalarda bu 4 işlemi bitirene kadar çalışmaya devam eder.
7. Traktörün her bir işlem için takip ettiği tarla sırası ve yolun maliyetini traktor_cikti.txt
dosyasına yazdırılacaktır

#Daha fazlası için mesaj atabilirsiniz yasinkaracaofficial@gmail.com
