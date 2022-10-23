//4 to 1 mux
//4-1 mux
module mux4_to_1(out, i0, i1, i2, i3, s0, s1);

output out;
input i0, i1, i2, i3;
input s0, s1;

wire s0n, s1n;
wire y0, y1, y2, y3;

not	(s0not, s0);
not	(s1not, s1);

and	(y0, i0, s0not, s1not);
and	(y1, i1, s0not, s1);
and	(y2, i2, s0, s1not);
and	(y3, i3, s0, s1);
or	(out, y0, y1, y2, y3);
endmodule

//8-bit 4-1 mux
module mux4_to_1_8b(out, d0, d1, d2, d3, s);
output [7:0] out;
input [7:0] d0;
input [7:0] d1;
input [7:0] d2;
input [7:0] d3;
input [1:0] s;

mux4_to_1 mux0(out[0], d0[0], d1[0], d2[0], d3[0], s[1], s[0]);
mux4_to_1 mux1(out[1], d0[1], d1[1], d2[1], d3[1], s[1], s[0]);
mux4_to_1 mux2(out[2], d0[2], d1[2], d2[2], d3[2], s[1], s[0]);
mux4_to_1 mux3(out[3], d0[3], d1[3], d2[3], d3[3], s[1], s[0]);
mux4_to_1 mux4(out[4], d0[4], d1[4], d2[4], d3[4], s[1], s[0]);
mux4_to_1 mux5(out[5], d0[5], d1[5], d2[5], d3[5], s[1], s[0]);
mux4_to_1 mux6(out[6], d0[6], d1[6], d2[6], d3[6], s[1], s[0]);
mux4_to_1 mux7(out[7], d0[7], d1[7], d2[7], d3[7], s[1], s[0]);

endmodule

//32-bit 4-1 mux
module mux4_to_1_32b(out, d0, d1, d2, d3, s);
output [31:0] out;
input [31:0] d0;
input [31:0] d1;
input [31:0] d2;
input [31:0] d3;
input [1:0] s;

mux4_to_1_8b mux0(out[7:0], d0[7:0], d1[7:0], d2[7:0], d3[7:0], s);
mux4_to_1_8b mux1(out[15:8], d0[15:8], d1[15:8], d2[15:8], d3[15:8], s);
mux4_to_1_8b mux2(out[23:16], d0[23:16], d1[23:16], d2[23:16], d3[23:16], s);
mux4_to_1_8b mux3(out[31:24], d0[31:24], d1[31:24], d2[31:24], d3[31:24], s);

endmodule

module stimulus;
reg [31:0] d0, d1, d2, d3;
reg [1:0] S;
reg as;
wire [31:0] OUT;
wire [4:0] d0_1;

mux4_to_1_32b mymux1(OUT, d0, d1, d2, d3, S);

initial
	begin 
	d0[31:0] = 32'd10;
	d1[31:0] = 32'd100;
	d2[31:0] = 32'd0;
	d3[31:0] = 32'd200;
	#1 $display("d0 = %b\n", d0);
	#1 $display("d1 = %b\n", d1);
	#1 $display("d2 = %b\n", d2);
	#1 $display("d3 = %b\n", d3);
	
	//00
	S = 2'b00;
	#5 $display("S = %b, OUT1 = %b\n", S, OUT);
	
	//01
	S = 2'b01;
	#5 $display("S = %b, OUT2 = %b\n", S, OUT);
	
	//10
	S = 2'b10;
	#5 $display("S = %b, OUT3 = %b\n", S, OUT);
	
	//11
	S = 2'b11;
	#5 $display("S = %b, OUT4 = %b\n", S, OUT);
	//xor
	as = 0;
	xor(d0_1[0], d0[0], as);
	xor(d0_1[1], d0[1], as);
	xor(d0_1[2], d0[2], as);
	xor(d0_1[3], d0[3], as);
	xor(d0_1[4], d0[4], as);
	#5 $display("d0 = %b, d0_1 = %b\n", d0, d0_1);
	end
endmodule