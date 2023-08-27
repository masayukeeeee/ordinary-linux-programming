# メモ

* File offset  
  * streamはファイルに繋がっている
  * `read()`で繰り返しstreamを呼び出すと、必ず前回の続きが返却される
  * つまりstreamはファイルへの接続の他にファイル内の特定の位置情報を保持している
  * これをfile offsetと呼ぶ。
  * file offsetはstreamの属性
  * システムコールにはfile offsetを操作する関数もある。
  * `lseek()`はその代表例

