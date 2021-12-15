let
  hostPkgs = import <nixpkgs> {};
  pkgs = import <nixpkgs> {
    crossSystem = (import <nixpkgs/lib>).systems.examples.armv7l-hf-multiplatform;
  };
in
pkgs.mkShell rec {
  depsBuildBuild = [hostPkgs.buildPackages.stdenv.cc ];
  nativeBuildInputs = with hostPkgs.buildPackages; [
    bc
    bison 
    flex
    gmp
    libmpc
    libyaml
    dt-schema
    lzop
    mpfr
    perl
    pkg-config
    ncurses
    openssl
   ];
  buildInputs = with pkgs; [ zlib ]; 
  shellHook = ''
    export O=out
    export CROSS_COMPILE=armv7l-unknown-linux-gnueabihf-
    export CC=armv7l-unknown-linux-gnueabihf-cc
    export HOSTCC=cc
    export ARCH=arm
    export PKG_CONFIG_PATH="${hostPkgs.ncurses.dev}/lib/pkgconfig:${hostPkgs.libyaml}/lib/pkgconfig"
  '';
}
