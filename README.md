# pisi-lightdm-greeter 
[ENGLISH](https://github.com/ayhanyalcinsoy/pisi-lightDM-greeter/blob/master/README_EN.md)
## Tanım

pisi-lightdm-greeter, C++ ve Qt5 dilinde yazılmış ve lightdm yüklü sistemlerde kullanılabilecek bir giriş ekranı uygulamasıdır.  [hvl-lightdm-greeter](https://github.com/aciklab/Hvl-Lightdm-Greeter) 'dan çatallanmıştır.

Bu giriş ekranı, süresi dolmuş parolaları sıfırlama imkanı verebilmektedir (Windows aktif dizin hesapları ve yerel kullanıcı hesapları ile test edilmiştir). 
Eğer bir parolanın değiştirlmesi gerekiyorsa giriş sırasında kullanıcının parolasını sıfırlaması istenir. Arkasından parola sıfırlama sayfası açılarak kullanıcının parolasını sıfırlaması sağlanır.

## Özellikler 

* Oturum açmadan ağ bağlantısı gerçekleşmesi durumunda IP adresi ve istenilen servislerin durumunun gözükebilmesi, istenildiği taktirde logların izlenebilmesi.
* Bir web servis aracılığı ile selfservis parola sıfırlama uygulaması varsa ona qtwebengine ile bağlantı eklenebilmesi.
* Etki alanı veya yerel kullanıcının parola süresi dolduğunda yeni bir popup açılarak düzgün şekilde parola değiştirmeyi sağlamakta.
* PAM'dan dönen promtlar daha doğru şekilde ekrana uyarı göstermekte. (pam_unix ve pam_sssd üzerinde çalışılmıştır, winbind üzerinde cache gibi işlemlerde dönen içeriklerde uyarı metni konusunda eksiklik olabilir)
* Ağ bağlantısı gerçekleşmeden giriş yapılabilecek ekranın gözükmemesi sağlanabilmektedir. (yavaş ağlar için belirli timeout değerine göre)
* İstenilen sayıda kişi ikonu gözükebilmesi. Makine etki alanında ise tüm listeyi çekme yavaşlığının önüne geçilmesi.
* Klasör bazlı arkaplan gösterim modu.
* Maddeler konfigüre edilebilir dosya üzerinde tutulması.
* Dokunmatik ekranlar için Ekran klavyesi seçeneği.

Giriş ekranı Pisi GNU/Linux üzerinde test edilmiştir.


## Kurulum

### Derleme

Kodu derlemek için, 
- qt5-default
- cmake
- qtwebengine5-dev 
- libqt5x11extras5-dev
- liblightdm-qt5-3-dev
- libxcursor-dev
- libxrandr-dev 
- lightdm
- qttools5-dev
- qttools5-dev-tools

paketlerinin sisteminizde kurulu olduğuna emin olun

Çalıştırmak için bağımlılıklar şunlardır: lightdm, libqt5webenginewidgets5, liblightdm-qt5-3-0, libqt5webengine5, libx11-6, libxcursor1, libqt5x11extras5

Kurulum için, aşağıdaki komutları çalıştırın:

```shell
git clone https://github.com/ayhanyalcinsoy/pisi-lightDM-greeter.git
cd pisi-lightDM-greeter
mkdir build && cd build
cmake ..
make 
sudo make install
```
 `/etc/lightdm/lightdm.conf`, dosyası içinde, `SeatDefaults` bölümü altına aşağıdaki satırı ekleyin ya da başka bir değere atanmışsa güncelleyin:

    greeter-session=pisi-lightdm-greeter

Eğer böyle bir dosya mevcut değilse oluşturun.	

### Pisi GNU/Linux üzerine kurulum

Paket Yöneticisini kullanarak ya da terminalde aşağıdaki komut ile kurabilirsiniz:
```
sudo pisi it pisi-lightdm-greeter

```

## Yapılandırma

`/usr/share/lightdm/lightdm-pisi-greeter.conf.d/pisi-lightdm-greeter.conf` dosyası içinde kullanılabilecek çeşitli konfigürasyon seçenekleri bulunmaktadır. Örnek olarak: 
	-Arka plan resmi, 
	-Giriş, saat ve ayar formlarının pozisyonları, 
	-Beklenmesi gereken servisler vb..
Bu dosya içinde detaylı açıklamalar yapılmıştır. 

<img src="https://raw.githubusercontent.com/ayhanyalcinsoy/pisi-lightDM-greeter/master/ss/screen_shoot.jpg">
