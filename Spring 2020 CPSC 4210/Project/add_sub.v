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

output [3:0] ss;
output cc;
input [3:0] a, b;
input c;

wire c1, c2, c3;
wire [3:0] y;

xor (y[0], b[0], c);
xor (y[1], b[1], c);
xor (y[2], b[2], c);
xor (y[3], b[3], c);

full_adder fa0(c1, ss[0], a[0], y[0], c);
full_adder fa1(c2, ss[1], a[1], y[1], c1);
full_adder fa2(c3, ss[2], a[2], y[2], c2);
full_adder fa3(cc, ss[3], a[3], y[3], c3);

endmodule

module stimulus;
reg [3:0] A, B;
reg C;

wire [3:0] SS;
wire CC;

adder_sub myadd_sub(CC, SS, A, B, C);
initial
	begin
		$monitor($time,"A=%d, B=%d, C=%b, ---CC=%b, SS=%d\n", A, B, C, CC, SS);
	end
initial
	begin
		A=4'd0; B=4'd0; C=1'b0;
		#5 A=4'd3; B=4'd4;
		#5 A=4'd5; B=4'd2; C=1'b1;
		#5 A=4'd5; B=4'd10;
		#5 A=4'd2; B=4'd10; C=1'b0;
		#5 A=4'd10; B=4'd5; C=1'b1;
	end
endmodule
		