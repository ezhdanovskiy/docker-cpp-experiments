
FROM gcc:latest as build

ENV CCACHE_DIR /ccache

VOLUME /ccache

RUN set -ex && \
    apt-get update && \
    apt-get install -y \
      libgtest-dev \
      cmake \
      time \
      vim \
      ccache

WORKDIR /gtest_build

RUN set -ex && \
    ccache -s && \
    time -p cmake -DCMAKE_BUILD_TYPE=Release CMAKE_C_COMPILER=/usr/lib/ccache/gcc-6 -D CMAKE_CXX_COMPILER=/usr/lib/ccache/g++-6 /usr/src/gtest && \
    ccache -s && \
    time -p cmake --build . && \
    ccache -s && \
    mv lib*.a /usr/lib

# Скопируем директорию /src в контейнер
ADD ./src /app/src

# Установим рабочую директорию для сборки проекта
WORKDIR /app/build

# Выполним сборку нашего проекта, а также его тестирование
RUN set -ex && \
    env && \
    ccache -s && \
    time -p cmake -DCMAKE_BUILD_TYPE=Release -D CMAKE_C_COMPILER=/usr/lib/ccache/gcc-6 -D CMAKE_CXX_COMPILER=/usr/lib/ccache/g++-6 ../src && \
    ccache -s && \
    time -p cmake --build . && \
    ccache -s && \
    ctest --verbose

ADD .build/run-inside.sh /app/build/run.sh

CMD ["/app/build/run.sh"]
