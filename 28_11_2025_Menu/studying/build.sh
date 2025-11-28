FILES="main.cpp menu_functions.cpp"
APP="./bin/app"

if [ -f $APP ]; then rm $APP
fi

mkdir -p "bin"

g++ $FILES -o $APP

./$APP
