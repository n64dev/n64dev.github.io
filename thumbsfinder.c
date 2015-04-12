/*****************************************************************
 * thumbsfinder.c - find references to thumbnails in html.
 * 2015 jrra.
 * 
 * Based on outline.c. Copyright 1999, Clark Cooper.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the license contained in the
 * COPYING file that comes with the expat distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Read an XML document from standard input and print an element
 * outline on standard output.
 * Must be used with Expat compiled for UTF-8 output.
 */

#include <string.h>     // for strstr
#include <stdio.h>
#include <expat.h>

#if defined(__amigaos__) && defined(__USE_INLINE__)
#include <proto/expat.h>
#endif

#ifdef XML_LARGE_SIZE
#if defined(XML_USE_MSC_EXTENSIONS) && _MSC_VER < 1400
#define XML_FMT_INT_MOD "I64"
#else
#define XML_FMT_INT_MOD "ll"
#endif
#else
#define XML_FMT_INT_MOD "l"
#endif

#define BUFFSIZE        8192

char Buff[BUFFSIZE];

static void XMLCALL
start(void *data, const char *el, const char **attr)
{
  int i;
  
  // <a href="i/...">
  if( !strcmp( el, "a" ) )
      for(i=0; attr[i]; i+=2)
          if( !strcmp( attr[i], "href" ) )
          {
              if( attr[i+1] == strstr( attr[i+1], "i/l" ) )
                printf("%s ", attr[i+1]);
              else if( attr[i+1] == strstr( attr[i+1], "i/m" ) )
                printf("%s ", attr[i+1]);
              else if( attr[i+1] == strstr( attr[i+1], "i/t" ) )
                printf("%s ", attr[i+1]);
          }
              
  // <img src="i/...">
  if( !strcmp( el, "img" ) )
      for(i=0; attr[i]; i+=2)
          if( !strcmp( attr[i], "src" ) )
          {
              if( attr[i+1] == strstr( attr[i+1], "i/l" ) )
                printf("%s ", attr[i+1]);
              else if( attr[i+1] == strstr( attr[i+1], "i/m" ) )
                printf("%s ", attr[i+1]);
              else if( attr[i+1] == strstr( attr[i+1], "i/t" ) )
                printf("%s ", attr[i+1]);
          }
}

static void XMLCALL
end(void *data, const char *el)
{
}

int
main(int argc, char *argv[])
{
  XML_Parser p = XML_ParserCreate(NULL);
  if (! p) {
    fprintf(stderr, "Couldn't allocate memory for parser\n");
    exit(-1);
  }

  XML_SetElementHandler(p, start, end);

  printf("thumbs: ");
  for (;;) {
    int done;
    int len;

    len = (int)fread(Buff, 1, BUFFSIZE, stdin);
    if (ferror(stdin)) {
      fprintf(stderr, "Read error\n");
      exit(-1);
    }
    done = feof(stdin);

    if (XML_Parse(p, Buff, len, done) == XML_STATUS_ERROR) {
      fprintf(stderr, "Parse error at line %" XML_FMT_INT_MOD "u:\n%s\n",
              XML_GetCurrentLineNumber(p),
              XML_ErrorString(XML_GetErrorCode(p)));
      exit(-1);
    }

    if (done)
      break;
  }
  printf("\n\n");
  XML_ParserFree(p);
  return 0;
}