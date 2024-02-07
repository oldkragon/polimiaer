FUNZIONI PER FILE:

fopen: Apre un file ==> FILE *f = fopen(filename, mode)

File access
mode string 	Meaning 	              Explanation 	            Action if file already exists         Action if file does not exist

"r" 	         read 	            Open a file for reading 	        read from start 	                failure to open
"w" 	         write 	            Create a file for writing 	        destroy contents 	                create new
"a" 	         append 	        Append to a file 	                write to end 	                    create new
"r+" 	         read extended 	    Open a file for read/write 	        read from start 	                error
"w+" 	         write extended 	Create a file for read/write 	    destroy contents 	                create new
"a+" 	         append extended 	Open a file for read/write 	        write to end 	                    create new

fclose: Chiude un file ==> fclose(f);

fread: Legge dati da un file ==> size_t fread(void *buffer, size_t size, size_t count, FILE *stream)
                                 fread(buffer, 1, 10, file) // legge i 10 caratteri dopo
buffer 	- 	pointer to the array where the read objects are stored
size 	- 	size of each object in bytes
count 	- 	the number of the objects to be read
stream 	- 	the stream to read

fwrite: Scrive dati su un file ==> size_t fwrite( const void* buffer, size_t size, size_t count,
                                                  FILE* stream);
fseek: Sposta il puntatore del file ==> int fseek( FILE *stream, long offset, int origin );
stream 	- 	file stream to modify
offset 	- 	number of characters to shift the position relative to origin
origin 	- 	position to which offset is added. It can have one of the following values: SEEK_SET, SEEK_CUR, SEEK_END
SEEK_CUR -	Posizione corrente del puntatore del file. ==> fseek(file, 20, SEEK_CUR) // Sposta il cursore 20 posizioni avanti
SEEK_END -	Fine del file. ==> fseek(file, 0, SEEK_END) // Sposta il cursore alla fine del file
SEEK_SET -	Inizio del file. ==> fseek(file, 100, SEEK_SET) // Sposta il cursore alla posizione 100 nel file
                                 fseek(file, 0, SEEK_SET) // Sposta il cursore all'inizio del file

ftell: Ottiene la posizione corrente del puntatore del file ==> ftell( FILE *stream)

rewind: Riporta il puntatore del file all’inizio ==> void rewind( FILE *stream)

fprintf: Scrive una stringa formattata su un file ==> int fprintf( FILE *stream, const char *format, ... )

fscanf: Legge dati formattati da un file ==> int fscanf( std::FILE* stream, const char* format, ... )// legge fino a spazio, tabulazione o nuova riga (o finchè non incontra qualcosa non del formato), il cursore si ferma appena prima del carattere che non corrisponde al formato specificato

fgets: Legge una line di testo da un file ==> char *fgets( char *str, int count, FILE *stream )// si ferma quando incontra un carattere di nuova riga, la fine del file, o ha letto un numero di caratteri specificato meno uno, il cursore si ferma appena dopo il carattere di nuova linea, se presente

fgetc: Legge un carattere nel file ==> int fgetc( FILE *stream )

fputc: Scrive un carattere in un file ==> int fputc( int ch, std::FILE* stream )

FUNZIONI PER STRINGHE

strcpy: Copia una stringa in un’altra ==> char* strcpy( char* dest, const char* source )

strncpy: Copia un numero specifico di caratteri da una stringa all’altra ==> char *strncpy( char *dest, const char *src, size_t count )
dest 	- 	pointer to the character array to copy to
source 	- 	pointer to the character array to copy from
count 	- 	maximum number of characters to copy
destsz 	- 	the size of the destination buffer

strcat: Concatena due stringhe ==> char* strcat( char* dest, const char* src )

strncat: Concatena un numero specifico di caratteri da una stringa all’altra ==> char* strncat( char* dest, const char* src, std::size_t count )

strcmp: Confronta due stringhe ==> int strcmp( const char* lhs, const char* rhs )
- Negative value if lhs appears before rhs in lexicographical order.
- Zero if lhs and rhs compare equal.
- Positive value if lhs appears after rhs in lexicographical order.

strncmp: Confronta un numero specifico di caratteri tra due stringhe ==> int strncmp( const char* lhs, const char* rhs, std::size_t count )

strlen: Restituisce la lunghezza di una stringa ==> std::size_t strlen( const char* str )// NON CONTA IL TERMINATORE

strchr: Trova la prima occorrenza di un carattere in una stringa ==> char *strchr( const char *str, int ch )// retituisce puntatore alla prima occorrenza

strstr: Trova la prima occorrenza di una sottostringa in una stringa ==> char *strstr( const char *str, const char *substr )// restituisce puntatore al primo carattere della sottostringa trovata

sscanf: Legge dati formattati da una stringa ==> int sscanf( const char* buffer, const char* format, ... )// legge fino a spazio, tabulazione o nuova riga (o finchè non incontra qualcosa non del formato), il cursore si ferma appena prima del carattere che non corrisponde al formato specificato

sprintf: Scrive i dati formattati in una stringa ==> int sprintf( char *buffer(destination), const char *format, ...(source) )

snprintf: Include un parametro di dimensione (max della destinazione) ==> int snprintf( char *restrict buffer, size_t bufsz, const char *restrict format, ... )

memset: Riempie un blocco di memoria con un determinato valore ==> void *memset(void *ptr, int x, size_t n);

FUNZIONI PER INPUT/OUTPUT

getchar: Legge un carattere dallo standard input ==> int getchar( void )

putchar: Scrive un carattere sullo standard output ==> int putchar( int ch )

getc: Legge un carattere da uno stream (file o input) ==> int getc( FILE *stream )

putc: Scrive un carattere in un flusso di output specificato ==> int putc( int ch, std::FILE* stream )

gets: Legge una stringa dallo standard input ==> char *gets( char *str )// si ferma quando incontra il carattere nuova riga o raggiunge la fine del file

puts: Scrive una stringa sullo standard output ==> int puts( const char* str )

scanf: Legge dati formattati dallo standard input ==> int scanf( const char* format, ... )// legge fino a spazio, tabulazione o nuova riga (o finchè non incontra qualcosa non del formato), il cursore si ferma appena prima del carattere che non corrisponde al formato specificato

printf: Scrive dati formattati sullo standard output ==> int printf( const char *format, ... )
