#!/bin/bash
# 引数に指定するツールのバージョンを全て表示する。

# 引数指定のツール数分ループ
for TOOL in $@; do  
  # 標準出力：ツールの場所
  which $TOOL;
  # :標準出力：ツールの version
  $TOOL --version | head -n 1 | sed -e 's/^/\t/' -e 's/$/\n/'
done
# プログラム終了コード返却
exit 0
