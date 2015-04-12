<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta name="Generator" content="Kate, the KDE Advanced Text Editor" />
<title>n64crc.c</title>
</head>
<body>
<pre style='color:#141312;background-color:#ffffff;'>
<i><span style='color:#888786;'>/*</span></i><i><span style='color:#888786;'> snesrc - SNES Recompiler</span></i>
<i><span style='color:#888786;'> *</span></i>
<i><span style='color:#888786;'> * Mar 23, 2010: addition by spinout to actually fix CRC if it is incorrect</span></i>
<i><span style='color:#888786;'> *</span></i>
<i><span style='color:#888786;'> * Copyright notice for this file:</span></i>
<i><span style='color:#888786;'> *  Copyright (C) 2005 Parasyte</span></i>
<i><span style='color:#888786;'> *</span></i>
<i><span style='color:#888786;'> * Based on uCON64's N64 checksum algorithm by Andreas Sterbenz</span></i>
<i><span style='color:#888786;'> *</span></i>
<i><span style='color:#888786;'> * This program is free software; you can redistribute it and/or modify</span></i>
<i><span style='color:#888786;'> * it under the terms of the GNU General Public License as published by</span></i>
<i><span style='color:#888786;'> * the Free Software Foundation; either version 2 of the License, or</span></i>
<i><span style='color:#888786;'> * (at your option) any later version.</span></i>
<i><span style='color:#888786;'> *</span></i>
<i><span style='color:#888786;'> * This program is distributed in the hope that it will be useful,</span></i>
<i><span style='color:#888786;'> * but WITHOUT ANY WARRANTY; without even the implied warranty of</span></i>
<i><span style='color:#888786;'> * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the</span></i>
<i><span style='color:#888786;'> * GNU General Public License for more details.</span></i>
<i><span style='color:#888786;'> *</span></i>
<i><span style='color:#888786;'> * You should have received a copy of the GNU General Public License</span></i>
<i><span style='color:#888786;'> * along with this program; if not, write to the Free Software</span></i>
<i><span style='color:#888786;'> * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA</span></i>
<i><span style='color:#888786;'> </span></i><i><span style='color:#888786;'>*/</span></i>


<span style='color:#006e28;'>#include </span><span style='color:#006e28;'>&lt;stdio.h&gt;</span>
<span style='color:#006e28;'>#include </span><span style='color:#006e28;'>&lt;stdlib.h&gt;</span>

<span style='color:#006e28;'>#define ROL(i, b) (((i) </span><span style='color:#006e28;'>&lt;&lt; (b)) | ((i) &gt;</span><span style='color:#006e28;'>&gt; (32 - (b))))</span>
<span style='color:#006e28;'>#define BYTES2LONG(b) ( (b)[0] &lt;&lt; 24 | \</span>
<span style='color:#006e28;'>                        (b)[1] &lt;&lt; 16 | \</span>
<span style='color:#006e28;'>                        (b)[2] &lt;&lt;  8 | \</span>
<span style='color:#006e28;'>                        (b)[3] )</span>

<span style='color:#006e28;'>#define N64_HEADER_SIZE  0x40</span>
<span style='color:#006e28;'>#define N64_BC_SIZE      (0x1000 - N64_HEADER_SIZE)</span>

<span style='color:#006e28;'>#define N64_CRC1         0x10</span>
<span style='color:#006e28;'>#define N64_CRC2         0x14</span>

<span style='color:#006e28;'>#define CHECKSUM_START   0x00001000</span>
<span style='color:#006e28;'>#define CHECKSUM_LENGTH  0x00100000</span>
<span style='color:#006e28;'>#define CHECKSUM_CIC6102 0xF8CA4DDC</span>
<span style='color:#006e28;'>#define CHECKSUM_CIC6103 0xA3886759</span>
<span style='color:#006e28;'>#define CHECKSUM_CIC6105 0xDF26F436</span>
<span style='color:#006e28;'>#define CHECKSUM_CIC6106 0x1FEA617A</span>

<span style='color:#006e28;'>#define Write32(Buffer, Offset, Value)\</span>
<span style='color:#006e28;'>	Buffer[Offset] = (Value &amp; 0xFF000000) &gt;&gt; 24;\</span>
<span style='color:#006e28;'>	Buffer[Offset + 1] = (Value &amp; 0x00FF0000) &gt;&gt; 16;\</span>
<span style='color:#006e28;'>	Buffer[Offset + 2] = (Value &amp; 0x0000FF00) &gt;&gt; 8;\</span>
<span style='color:#006e28;'>	Buffer[Offset + 3] = (Value &amp; 0x000000FF);\</span>

<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> crc_table[<span style='color:#b08000;'>256</span>];

<span style='color:#0057ae;'>void</span> gen_table() {
	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> crc, poly;
	<span style='color:#0057ae;'>int</span>	i, j;

	poly = <span style='color:#b08000;'>0xEDB88320</span>;
	<b>for</b> (i = <span style='color:#b08000;'>0</span>; i &lt; <span style='color:#b08000;'>256</span>; i++) {
		crc = i;
		<b>for</b> (j = <span style='color:#b08000;'>8</span>; j &gt; <span style='color:#b08000;'>0</span>; j--) {
			<b>if</b> (crc &amp; <span style='color:#b08000;'>1</span>) crc = (crc &gt;&gt; <span style='color:#b08000;'>1</span>) ^ poly;
			<b>else</b> crc &gt;&gt;= <span style='color:#b08000;'>1</span>;
		}
		crc_table[i] = crc;
	}
}

<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> crc32(<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>char</span> *data, <span style='color:#0057ae;'>int</span> len) {
	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> crc = ~<span style='color:#b08000;'>0</span>;
	<span style='color:#0057ae;'>int</span> i;

	<b>for</b> (i = <span style='color:#b08000;'>0</span>; i &lt; len; i++) {
		crc = (crc &gt;&gt; <span style='color:#b08000;'>8</span>) ^ crc_table[(crc ^ data[i]) &amp; <span style='color:#b08000;'>0xFF</span>];
	}

	<b>return</b> ~crc;
}


<span style='color:#0057ae;'>int</span> N64GetCIC(<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>char</span> *data) {
	<b>switch</b> (crc32(&amp;data[N64_HEADER_SIZE], N64_BC_SIZE)) {
		<b>case</b> <span style='color:#b08000;'>0x6170A4A1</span>: <b>return</b> <span style='color:#b08000;'>6101</span>;
		<b>case</b> <span style='color:#b08000;'>0x90BB6CB5</span>: <b>return</b> <span style='color:#b08000;'>6102</span>;
		<b>case</b> <span style='color:#b08000;'>0x0B050EE0</span>: <b>return</b> <span style='color:#b08000;'>6103</span>;
		<b>case</b> <span style='color:#b08000;'>0x98BC2C86</span>: <b>return</b> <span style='color:#b08000;'>6105</span>;
		<b>case</b> <span style='color:#b08000;'>0xACC8580A</span>: <b>return</b> <span style='color:#b08000;'>6106</span>;
	}

	<b>return</b> <span style='color:#b08000;'>6105</span>;
}

<span style='color:#0057ae;'>int</span> N64CalcCRC(<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> *crc, <span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>char</span> *data) {
	<span style='color:#0057ae;'>int</span> bootcode, i;
	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> seed;

	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> t1, t2, t3;
	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> t4, t5, t6;
	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> r, d;


	<b>switch</b> ((bootcode = N64GetCIC(data))) {
		<b>case</b> <span style='color:#b08000;'>6101</span>:
		<b>case</b> <span style='color:#b08000;'>6102</span>:
			seed = CHECKSUM_CIC6102;
			<b>break</b>;
		<b>case</b> <span style='color:#b08000;'>6103</span>:
			seed = CHECKSUM_CIC6103;
			<b>break</b>;
		<b>case</b> <span style='color:#b08000;'>6105</span>:
			seed = CHECKSUM_CIC6105;
			<b>break</b>;
		<b>case</b> <span style='color:#b08000;'>6106</span>:
			seed = CHECKSUM_CIC6106;
			<b>break</b>;
		<b>default</b>:
			<b>return</b> <span style='color:#b08000;'>1</span>;
	}

	t1 = t2 = t3 = t4 = t5 = t6 = seed;

	i = CHECKSUM_START;
	<b>while</b> (i &lt; (CHECKSUM_START + CHECKSUM_LENGTH)) {
		d = BYTES2LONG(&amp;data[i]);
		<b>if</b> ((t6 + d) &lt; t6) t4++;
		t6 += d;
		t3 ^= d;
		r = ROL(d, (d &amp; <span style='color:#b08000;'>0x1F</span>));
		t5 += r;
		<b>if</b> (t2 &gt; d) t2 ^= r;
		<b>else</b> t2 ^= t6 ^ d;

		<b>if</b> (bootcode == <span style='color:#b08000;'>6105</span>) t1 += BYTES2LONG(&amp;data[N64_HEADER_SIZE + <span style='color:#b08000;'>0x0710</span> + (i &amp; <span style='color:#b08000;'>0xFF</span>)]) ^ d;
		<b>else</b> t1 += t5 ^ d;

		i += <span style='color:#b08000;'>4</span>;
	}
	<b>if</b> (bootcode == <span style='color:#b08000;'>6103</span>) {
		crc[<span style='color:#b08000;'>0</span>] = (t6 ^ t4) + t3;
		crc[<span style='color:#b08000;'>1</span>] = (t5 ^ t2) + t1;
	}
	<b>else</b> <b>if</b> (bootcode == <span style='color:#b08000;'>6106</span>) {
		crc[<span style='color:#b08000;'>0</span>] = (t6 * t4) + t3;
		crc[<span style='color:#b08000;'>1</span>] = (t5 * t2) + t1;
	}
	<b>else</b> {
		crc[<span style='color:#b08000;'>0</span>] = t6 ^ t4 ^ t3;
		crc[<span style='color:#b08000;'>1</span>] = t5 ^ t2 ^ t1;
	}

	<b>return</b> <span style='color:#b08000;'>0</span>;
}

<span style='color:#0057ae;'>int</span> main(<span style='color:#0057ae;'>int</span> argc, <span style='color:#0057ae;'>char</span> **argv) {
	FILE *fin;
	<span style='color:#0057ae;'>int</span> cic;
	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>int</span> crc[<span style='color:#b08000;'>2</span>];
	<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>char</span> *buffer;

	<i><span style='color:#888786;'>//Init CRC algorithm</span></i>
	gen_table();

	<i><span style='color:#888786;'>//Check args</span></i>
	<b>if</b> (argc != <span style='color:#b08000;'>2</span>) {
		printf(<span style='color:#bf0303;'>&quot;Usage: n64sums &lt;infile&gt;</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>);
		<b>return</b> <span style='color:#b08000;'>1</span>;
	}

	<i><span style='color:#888786;'>//Open file</span></i>
	<b>if</b> (!(fin = fopen(argv[<span style='color:#b08000;'>1</span>], <span style='color:#bf0303;'>&quot;r+b&quot;</span>))) {
		printf(<span style='color:#bf0303;'>&quot;Unable to open </span><span style='color:#ff80e0;'>\&quot;</span><span style='color:#bf0303;'>%s</span><span style='color:#ff80e0;'>\&quot;</span><span style='color:#bf0303;'> in mode </span><span style='color:#ff80e0;'>\&quot;</span><span style='color:#bf0303;'>%s</span><span style='color:#ff80e0;'>\&quot;\n</span><span style='color:#bf0303;'>&quot;</span>, argv[<span style='color:#b08000;'>1</span>], <span style='color:#bf0303;'>&quot;r+b&quot;</span>);
		<b>return</b> <span style='color:#b08000;'>1</span>;
	}

	<i><span style='color:#888786;'>//Allocate memory</span></i>
	<b>if</b> (!(buffer = (<span style='color:#0057ae;'>unsigned</span> <span style='color:#0057ae;'>char</span>*)malloc((CHECKSUM_START + CHECKSUM_LENGTH)))) {
		printf(<span style='color:#bf0303;'>&quot;Unable to allocate %d bytes of memory</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>, (CHECKSUM_START + CHECKSUM_LENGTH));
		fclose(fin);
		<b>return</b> <span style='color:#b08000;'>1</span>;
	}

	<i><span style='color:#888786;'>//Read data</span></i>
	<b>if</b> (fread(buffer, <span style='color:#b08000;'>1</span>, (CHECKSUM_START + CHECKSUM_LENGTH), fin) != (CHECKSUM_START + CHECKSUM_LENGTH)) {
		printf(<span style='color:#bf0303;'>&quot;Unable to read %d bytes of data (invalid N64 image?)</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>, (CHECKSUM_START + CHECKSUM_LENGTH));
		fclose(fin);
		free(buffer);
		<b>return</b> <span style='color:#b08000;'>1</span>;
	}

	<i><span style='color:#888786;'>//Check CIC BootChip</span></i>
	cic = N64GetCIC(buffer);
	printf(<span style='color:#bf0303;'>&quot;BootChip: &quot;</span>);
	printf((cic ? <span style='color:#bf0303;'>&quot;CIC-NUS-%d</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span> : <span style='color:#bf0303;'>&quot;Unknown</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>), cic);

	<i><span style='color:#888786;'>//Calculate CRC</span></i>
	<b>if</b> (N64CalcCRC(crc, buffer)) {
		printf(<span style='color:#bf0303;'>&quot;Unable to calculate CRC</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>);
	}
	<b>else</b> {
		printf(<span style='color:#bf0303;'>&quot;CRC 1: 0x%08X  &quot;</span>, BYTES2LONG(&amp;buffer[N64_CRC1]));
		printf(<span style='color:#bf0303;'>&quot;Calculated: 0x%08X &quot;</span>, crc[<span style='color:#b08000;'>0</span>]);
		<b>if</b> (crc[<span style='color:#b08000;'>0</span>] == BYTES2LONG(&amp;buffer[N64_CRC1]))
			printf(<span style='color:#bf0303;'>&quot;(Good)</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>);
		<b>else</b>{
			Write32(buffer, N64_CRC1, crc[<span style='color:#b08000;'>0</span>]);
			fseek(fin, N64_CRC1, SEEK_SET);
			fwrite(&amp;buffer[N64_CRC1], <span style='color:#b08000;'>1</span>, <span style='color:#b08000;'>4</span>, fin);
			printf(<span style='color:#bf0303;'>&quot;(Bad, fixed)</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>);
		}

		printf(<span style='color:#bf0303;'>&quot;CRC 2: 0x%08X  &quot;</span>, BYTES2LONG(&amp;buffer[N64_CRC2]));
		printf(<span style='color:#bf0303;'>&quot;Calculated: 0x%08X &quot;</span>, crc[<span style='color:#b08000;'>1</span>]);
		<b>if</b> (crc[<span style='color:#b08000;'>1</span>] == BYTES2LONG(&amp;buffer[N64_CRC2]))
			printf(<span style='color:#bf0303;'>&quot;(Good)</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>);
		<b>else</b>{
			Write32(buffer, N64_CRC2, crc[<span style='color:#b08000;'>1</span>]);
			fseek(fin, N64_CRC2, SEEK_SET);
			fwrite(&amp;buffer[N64_CRC2], <span style='color:#b08000;'>1</span>, <span style='color:#b08000;'>4</span>, fin);
			printf(<span style='color:#bf0303;'>&quot;(Bad, fixed)</span><span style='color:#ff80e0;'>\n</span><span style='color:#bf0303;'>&quot;</span>);
		}
	}

	fclose(fin);
	free(buffer);

	<b>return</b> <span style='color:#b08000;'>0</span>;
}
</pre>
</body>
</html>
