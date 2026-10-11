BUILD_TYPE=Ninja
BUILD_SUFFIX=ninja

BUILD_FOLDER=build_$BUILD_SUFFIX
SOURCE_FOLDER=.
IMG_FOLDER=img

if [ ! -d "$BUILD_FOLDER" ]; then
  mkdir $BUILD_FOLDER
fi

cd $BUILD_FOLDER

cmake -G $BUILD_TYPE ../$SOURCE_FOLDER
cmake --build .

if [ ! -d "$IMG_FOLDER" ]; then
  mkdir $IMG_FOLDER
  cp ../$IMG_FOLDER/veseli_smail.png $IMG_FOLDER
fi

cd ..
