# LvglTemplate_CM4


#### Runtime dependency

```
sudo apt install libts-bin
```

#### Submodules

```
cd LvglTemplate_CM4
```
```
git clone https://github.com/lvgl/lvgl.git -b  v8.3.5
```

```
cd lv_porting
```

```
git clone https://github.com/lvgl/lv_drivers.git
git clone https://github.com/libts/tslib.git -b 1.22
```


#### Compilation

```
cd ..
mkdir build && cd build
cmake ..
make
```

#### Run

```
./play
```

