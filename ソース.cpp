#include <Windows.h>
#include <wchar.h>


wchar_t s[256], t[256];
int f;

int p;
int i = 1;

int WINAPI wWinMain(HINSTANCE hI, HINSTANCE hP, LPWSTR lpC, int nC)
{
	int l = wcslen(lpC);
	p = 0;
	for (; i < l; i++) {
		if (lpC[i] == L'\\') {
			i++;
			switch (lpC[i]) {
			case L'"':
				break;
			case L'n':
				lpC[i] = L'\n';
				break;
			case L't':
				lpC[i] = L'\t';
				break;
			}
		}
		else if (lpC[i] == L'"') break;
		s[p] = lpC[i];
		p++;
	}

	i++;
	for (; i < l; i++) {
		if (lpC[i] == L'"') break;
	}

	i++;
	p = 0;
	for (; i < l; i++) {
		if (lpC[i] == L'\\') {
			i++;
			switch (lpC[i]) {
			case L'"':
				break;
			case L'n':
				lpC[i] = L'\n';
				break;
			case L't':
				lpC[i] = L'\t';
				break;
			}
		}
		else if (lpC[i] == L'"') break;
		t[p] = lpC[i];
		p++;
	}

	i++;
	for (; i < l; i++) {
		if (lpC[i] != L' ') break;
	}

	swscanf_s(lpC + i, L"%X", &f);

	MessageBox(NULL, s, t, f);

	return 0;
}