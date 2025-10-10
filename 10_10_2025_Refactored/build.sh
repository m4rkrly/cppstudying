FILES="aio.cpp sorts.cpp main.cpp"
APP="./bin/sort"

if [ -f $APP ]; then rm $APP
fi

mkdir -p "bin"

g++ $FILES -o $APP

./$APP
