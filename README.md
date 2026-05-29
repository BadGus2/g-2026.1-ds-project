# g-2026.1-ds-project
Projeto para criacao de um Banco de Dados relacionado a industria de filmes e aplicacao de filtros nesse banco criado em C.

Directory Structure:

/g-2026.1-ds-project-----------------------------------------------------
    |                                                                   |
    -- /diskmanager     -> Writes in separate .bin file (leaf)          |
    |   |-- DiskManager.c                                               |
    |   |-- DiskManager.h                                               |
    |                                                                   |
    |                                                                   |
    -- /hashtable       -> HashTable library                            |
    |   |-- HashTable.h                                                 |
    |   |-- HashTable.c                                                 |
    |                                                                   |
    |                                                                   |
    -- /inputs          -> DataBase inputs folder                       |
    |   |-- Nodes.txt                                                   |
    |   |-- Relationships.txt                                           |
    |                                                                   |
    |                                                                   |
    -- /outputs                                                         |
    |   |-- index.bin   -> B+ Tree                                      |
    |   |-- leaf_*.bin  -> All leaf files                               |
    |                                                                   |
    |                                                                   |
    -- /types           -> Register types                               |
    |   |-- /movie      -> To write in separate .bin file (leaf)        |
    |   |      |-- Movie.c                                              |
    |   |      |-- Movie.h                                              |
    |   |                                                               |
    |   |-- /person     -> To write in separate .bin file (leaf)        |
    |   |      |-- Person.c                                             |
    |   |      |-- Person.h                                             |
    |   |                                                               |
    |   |-- /tree       -> To write in index.bin file (TreeNode)        |
    |   |      |-- Tree.c                                               |
    |   |      |-- Tree.h                                               |
    |   |                                                               |
    -- main.c -> DataBase running (with UI)                             |
-------------------------------------------------------------------------