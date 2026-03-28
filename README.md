# libft

## 概要

C 言語の標準ライブラリに相当するユーティリティ関数を自作し、静的ライブラリ `libft.a` としてビルドするプロジェクトです。

## 目的

- C 言語の基礎（ポインタ操作、動的メモリ管理、文字列・メモリ操作）を深く理解する
- `libc` の代表的な関数を自前で実装することで、各関数の内部動作を把握する
- 今後の 42 課題で再利用できる汎用ライブラリを構築する

---

## ビルド方法

```bash
cd libft
make        # 必須関数のみビルド → libft.a
make bonus  # ボーナス（連結リスト）も含めてビルド
make clean  # オブジェクトファイルを削除
make fclean # libft.a とオブジェクトファイルを削除
make re     # fclean → all
```

---

## 実装関数一覧

### 文字判定・変換

| 関数 | 説明 |
|------|------|
| `ft_isalpha` | アルファベットか判定 |
| `ft_isdigit` | 数字か判定 |
| `ft_isalnum` | 英数字か判定 |
| `ft_isascii` | ASCII 範囲か判定 |
| `ft_isprint` | 印字可能文字か判定 |
| `ft_tolower` | 大文字 → 小文字変換 |
| `ft_toupper` | 小文字 → 大文字変換 |

### 文字列操作

| 関数 | 説明 |
|------|------|
| `ft_strlen` | 文字列の長さを返す |
| `ft_strlcpy` | サイズ付き文字列コピー（BSD 系） |
| `ft_strlcat` | サイズ付き文字列連結（BSD 系） |
| `ft_strchr` | 先頭から文字を検索 |
| `ft_strrchr` | 末尾から文字を検索 |
| `ft_strncmp` | 先頭 n 文字の比較 |
| `ft_strnstr` | 長さ制限付き部分文字列検索 |
| `ft_strdup` | 文字列を複製（malloc） |
| `ft_substr` | 部分文字列を生成 |
| `ft_strjoin` | 2 つの文字列を連結 |
| `ft_strtrim` | 先頭・末尾から指定文字集合を除去 |
| `ft_split` | 区切り文字で文字列を分割して `char **` を返す |
| `ft_strmapi` | インデックス付きで各文字を写像して新文字列を生成 |
| `ft_striteri` | インデックス付きで各文字に関数を適用（副作用） |

### メモリ操作

| 関数 | 説明 |
|------|------|
| `ft_memset` | バイト列を指定値で埋める |
| `ft_bzero` | n バイトを 0 で埋める |
| `ft_memcpy` | メモリ領域をコピー |
| `ft_memmove` | 重なりを考慮したメモリコピー |
| `ft_memchr` | メモリ内のバイトを検索 |
| `ft_memcmp` | メモリ領域を比較 |
| `ft_calloc` | 指定サイズを 0 初期化してメモリ確保 |

### 変換・数値

| 関数 | 説明 |
|------|------|
| `ft_atoi` | 文字列 → `int` 変換 |
| `ft_itoa` | `int` → 文字列変換（malloc） |

### ファイル記述子への出力

| 関数 | 説明 |
|------|------|
| `ft_putchar_fd` | 1 文字を指定 fd に出力 |
| `ft_putstr_fd` | 文字列を指定 fd に出力 |
| `ft_putendl_fd` | 文字列 + 改行を指定 fd に出力 |
| `ft_putnbr_fd` | 整数を指定 fd に出力 |

### ボーナス：単方向連結リスト

`t_list` 構造体を用いた単方向連結リスト操作関数群です。

| 関数 | 説明 |
|------|------|
| `ft_lstnew` | 新しいノードを生成 |
| `ft_lstadd_front` | リスト先頭にノードを追加 |
| `ft_lstadd_back` | リスト末尾にノードを追加 |
| `ft_lstsize` | リストの要素数を返す |
| `ft_lstlast` | 最後のノードを返す |
| `ft_lstdelone` | 1 つのノードを削除（`del` で content を解放） |
| `ft_lstclear` | リスト全体を削除・解放 |
| `ft_lstiter` | 各ノードの content に関数を適用 |
| `ft_lstmap` | 各ノードを写像した新しいリストを生成 |

---

## コンパイルフラグ

```
cc -Wall -Wextra -Werror
```
