#define _CRT_SECURE_NO_WARNINGS

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <Windows.h>
#include <wchar.h>

wchar_t s[2][256];
int f;

void wcschg(wchar_t*, const wchar_t*, const wchar_t*);

int wmain(int argc, wchar_t* argv[]) {
	if (argc != 4) return 1;

	_setmode(_fileno(stdin), _O_WTEXT);

	for (int i = 1; i <= 2; i++) {
		wcschg(argv[i], L"\\n", L"\n");
		wcschg(argv[i], L"\\t", L"\t");
	}

	swscanf_s(argv[3], L"%X", &f);

	printf("%d", MessageBox(NULL, argv[1], argv[2], f));

	return 0;
}

void wcschg(wchar_t* buf, const wchar_t* str1, const wchar_t* str2)
{
	wchar_t tmp[1024 + 1];
	wchar_t* p;

	while ((p = wcsstr(buf, str1)) != NULL) {
		/* 見つからなくなるまで繰り返す
			  pは旧文字列の先頭を指している */
		*p = L'\0'; /* 元の文字列を旧文字列の直前で区切って */
		p += wcslen(str1);  /* ポインタを旧文字列の次の文字へ */
		wcscpy(tmp, p);             /* 旧文字列から後を保存 */
		wcscat(buf, str2);  /* 新文字列をその後につなぎ */
		wcscat(buf, tmp);   /* さらに残りをつなぐ */
	}
}