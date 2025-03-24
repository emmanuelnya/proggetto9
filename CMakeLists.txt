cmake_minimum_required(VERSION 3.10)
project(Progetto8)

set(CMAKE_CXX_STANDARD 20)

# Inclure les répertoires nécessaires pour le projet
include_directories(include)

add_subdirectory(lib/googletest)

add_executable(Progetto8
        main.cpp
        src/destinatario.cpp
        src/comptebancaire.cpp
        src/transaction.cpp
)

# Ajouter des tests seulement si l'option BUILD_TESTS est activée
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    # Cible pour les tests
    add_executable(tests
            tests/tests.cpp
            tests/tests_main.cpp
    )

    target_link_libraries(tests
            gtest
            gtest_main
    )

    # Activer les tests
    enable_testing()
endif()

