# Maintainer: zurg3 <zurg3mail@mail.ru>
pkgname=notepad
pkgver=0.4
pkgrel=1
pkgdesc="Simple text editor. Based on official Qt5 Notepad example."
arch=('x86_64')
url="https://github.com/zurg3/notepad"
license=('GPLv3')
depends=('qt5-base' 'qt5-tools')
makedepends=('git' 'cmake')
source=("https://github.com/zurg3/notepad/archive/v$pkgver.tar.gz")
md5sums=('SKIP')

prepare() {
  cd "$srcdir/$pkgname-$pkgver"
  mkdir build
}

build() {
  cd "$srcdir/$pkgname-$pkgver/build"
  cmake ..
  cmake --build .
}

package() {
  cd "$srcdir/$pkgname-$pkgver/build"
  make DESTDIR="$pkgdir" install
}
