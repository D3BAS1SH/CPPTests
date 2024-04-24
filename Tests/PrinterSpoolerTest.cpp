#include <windows.h>
#include <winspool.h>

int main() {

	HANDLE hPrinter;
	DWORD dwJobId;

	// Open a handle to the printer.
	hPrinter = OpenPrinter("My Printer", NULL, NULL);

	// Create a print job.
	dwJobId = StartDocPrinter(hPrinter, 1, (LPBYTE)"My Print Job", NULL);

	// Write data to the print job.
	WritePrinter(hPrinter, (LPBYTE)"This is my print job.", 17, NULL);

	// End the print job.
	EndDocPrinter(hPrinter);

	// Close the handle to the printer.
	ClosePrinter(hPrinter);

	return 0;
}