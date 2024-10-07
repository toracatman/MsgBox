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
		/* ������Ȃ��Ȃ�܂ŌJ��Ԃ�
			  p�͋�������̐擪���w���Ă��� */
		*p = L'\0'; /* ���̕��������������̒��O�ŋ�؂��� */
		p += wcslen(str1);  /* �|�C���^����������̎��̕����� */
		wcscpy(tmp, p);             /* �������񂩂���ۑ� */
		wcscat(buf, str2);  /* �V����������̌�ɂȂ� */
		wcscat(buf, tmp);   /* ����Ɏc����Ȃ� */
	}
}