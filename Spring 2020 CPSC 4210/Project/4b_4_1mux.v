//Tony Ho
//CPSC4210

module mux4_to_1(out, i0, i1, i2, i3, s1, s0);

output out;
input i0, i1, i2, i3;
input s1, s0;

wire s1n, s0n;
wire y0, y1, y2, y3;

not	(s1not, s1);
not	(s0not, s0);

and	(y0, i0, s1not, s0not);
and	(y1, i1, s1not, s0);
and	(y2, i2, s1, s0not);
and	(y3, i3, s1, s0);
or	(out, y0, y1, y2, y3);
endmodule

module mux4b_4_to_1(OUTPUT, a, b, c, d, select1, select0);

output [3:0] OUTPUT;
input [3:0] a;
input [3:0] b;
input [3:0] c;
input [3:0] d;
input select1, select0;

//Output
mux4_to_1 muxA(OUTPUT[0], a[0], a[1], a[2], a[3], select1, select0);
mux4_to_1 muxB(OUTPUT[1], b[0], b[1], b[2], b[3], select1, select0);
mux4_to_1 muxC(OUTPUT[2], c[0], c[1], c[2], c[3], select1, select0);
mux4_to_1 muxD(OUTPUT[3], d[0], d[1], d[2], d[3], select1, select0);

endmodule

module stimulus;
reg [3:0] A, B, C, D;
reg S1, S0;
wire [3:0] OUT;

mux4b_4_to_1 mymux1(OUT, A, B, C, D, S1, S0);

initial
	begin 
	A[0] = 1; A[1] = 0; A[2] = 1; A[3] = 0;
	B[0] = 0; B[1] = 1; B[2] = 0; B[3] = 1;
	C[0] = 0; C[1] = 0; C[2] = 1; C[3] = 1;
	D[0] = 1; D[1] = 1; D[2] = 0; D[3] = 0;
	#1 $display("ABCD_0 = %b%b%b%b\n", A[0], B[0], C[0], D[0]);
	#1 $display("ABCD_1 = %b%b%b%b\n", A[1], B[1], C[1], D[1]);
	#1 $display("ABCD_2 = %b%b%b%b\n", A[2], B[2], C[2], D[2]);
	#1 $display("ABCD_3 = %b%b%b%b\n", A[3], B[3], C[3], D[3]);
	
	//00
	S0 = 0; S1 = 0;
	#5 $display("S = %b%b, OUT1 = %b\n", S0, S1, OUT);
	
	//01
	S0 = 0; S1 = 1;
	#5 $display("S = %b%b, OUT2 = %b\n", S0, S1, OUT);
	
	//10
	S0 = 1; S1 = 0;
	#5 $display("S = %b%b, OUT3 = %b\n", S0, S1, OUT);
	
	//11
	S0 = 1; S1 = 1;
	#5 $display("S = %b%b, OUT4 = %b\n", S0, S1, OUT);
	end
endmodule