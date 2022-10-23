module full_adder(c_out, sum, a, b, c_in);

output sum, c_out;
input a, b;
input c_in;

wire ab, axob, abc;

xor(axob, a, b);
and(ab, a, b);

xor(sum, axob, c_in);
and(abc, axob, c_in);
or(c_out, ab, abc);

endmodule

module adder_sub(cc, ss, a, b, c);

output [31:0] ss;
output cc;
input [31:0] a, b;
input c;

wire [30:0] carry;
wire [31:0] y;

xor (y[0], b[0], c);
xor (y[1], b[1], c);
xor (y[2], b[2], c);
xor (y[3], b[3], c);
xor (y[4], b[4], c);
xor (y[5], b[5], c);
xor (y[6], b[6], c);
xor (y[7], b[7], c);
xor (y[8], b[8], c);
xor (y[9], b[9], c);
xor (y[10], b[10], c);
xor (y[11], b[11], c);
xor (y[12], b[12], c);
xor (y[13], b[13], c);
xor (y[14], b[14], c);
xor (y[15], b[15], c);
xor (y[16], b[16], c);
xor (y[17], b[17], c);
xor (y[18], b[18], c);
xor (y[19], b[19], c);
xor (y[20], b[20], c);
xor (y[21], b[21], c);
xor (y[22], b[22], c);
xor (y[23], b[23], c);
xor (y[24], b[24], c);
xor (y[25], b[25], c);
xor (y[26], b[26], c);
xor (y[27], b[27], c);
xor (y[28], b[28], c);
xor (y[29], b[29], c);
xor (y[30], b[30], c);
xor (y[31], b[31], c);

full_adder fa0(carry[0], ss[0], a[0], y[0], c);
full_adder fa1(carry[1], ss[1], a[1], y[1], carry[0]);
full_adder fa2(carry[2], ss[2], a[2], y[2], carry[1]);
full_adder fa3(carry[3], ss[3], a[3], y[3], carry[2]);
full_adder fa4(carry[4], ss[4], a[4], y[4], carry[3]);
full_adder fa5(carry[5], ss[5], a[5], y[5], carry[4]);
full_adder fa6(carry[6], ss[6], a[6], y[6], carry[5]);
full_adder fa7(carry[7], ss[7], a[7], y[7], carry[6]);
full_adder fa8(carry[8], ss[8], a[8], y[8], carry[7]);
full_adder fa9(carry[9], ss[9], a[9], y[9], carry[8]);
full_adder fa10(carry[10], ss[10], a[10], y[10], carry[9]);
full_adder fa11(carry[11], ss[11], a[11], y[11], carry[10]);
full_adder fa12(carry[12], ss[12], a[12], y[12], carry[11]);
full_adder fa13(carry[13], ss[13], a[13], y[13], carry[12]);
full_adder fa14(carry[14], ss[14], a[14], y[14], carry[13]);
full_adder fa15(carry[15], ss[15], a[15], y[15], carry[14]);
full_adder fa16(carry[16], ss[16], a[16], y[16], carry[15]);
full_adder fa17(carry[17], ss[17], a[17], y[17], carry[16]);
full_adder fa18(carry[18], ss[18], a[18], y[18], carry[17]);
full_adder fa19(carry[19], ss[19], a[19], y[19], carry[18]);
full_adder fa20(carry[20], ss[20], a[20], y[20], carry[19]);
full_adder fa21(carry[21], ss[21], a[21], y[21], carry[20]);
full_adder fa22(carry[22], ss[22], a[22], y[22], carry[21]);
full_adder fa23(carry[23], ss[23], a[23], y[23], carry[22]);
full_adder fa24(carry[24], ss[24], a[24], y[24], carry[23]);
full_adder fa25(carry[25], ss[25], a[25], y[25], carry[24]);
full_adder fa26(carry[26], ss[26], a[26], y[26], carry[25]);
full_adder fa27(carry[27], ss[27], a[27], y[27], carry[26]);
full_adder fa28(carry[28], ss[28], a[28], y[28], carry[27]);
full_adder fa29(carry[29], ss[29], a[29], y[29], carry[28]);
full_adder fa30(carry[30], ss[30], a[30], y[30], carry[29]);
full_adder fa31(cc, ss[31], a[31], y[31], carry[30]);

endmodule

module stimulus;
reg [31:0] A, B;
reg C;

wire [31:0] SS;
wire CC;

adder_sub myadd_sub(CC, SS, A, B, C);
initial
	begin
		$monitor($time,"A=%d, B=%d, C=%b, ---CC=%b, SS=%d\n", A, B, C, CC, SS);
	end
initial
	begin
		A=32'd0; B=32'd0; C=1'b0;
		#5 A=32'd39; B=32'd136; C = 1'b1;
		#5 A=32'b00000000000000000000000000000000; B=32'b11111111111111111111111111111111; C=1'b0;

	end
endmodule