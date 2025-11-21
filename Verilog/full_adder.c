
module halfadder(
    input A, B, 
    output S, C
);

    xor (S, A, B);
    and (C, A, B);

module fulladder(
    input A, B, Cin,
    output S, Cout
);

    wire AxorB, and1, and2;
    
    xor (AxorB, A, B);
    xor (S, AxorB, Cin);

    and (and1, Cin, AxorB);
    and (and2, A, B);

    or (Cout, and1, and2);

endmodule


module paralleladder4bit(
    input A3, A2, A1, A0, B3, B2, B1, B0, Cin0
    output S0, S1, S2, S3, Cout3
);

    wire Cout0, Cout1, Cout2;
    
    fulladder FA0(A0, B0, Cin0, S0, Cout0);
    fulladder FA1(A1, B1, Cout0, S1, Cout1);
    fulladder FA2(A2, B2, Cout1, S2, Cout2);
    fulladder FA3(A3, B3, Cout2, S3, Cout3);

endmodule


module paralleladder4bit(
    input [3:0] A,
    input [3:0] B,
    input Cin0,
    output [3:0] S, 
    output Cout3
);

    wire Cout0, Cout1, Cout2;
    
    fulladder FA0(A[0], B[0], Cin0, S[0], Cout0);
    fulladder FA1(A[1], B[1], Cout0, S[1], Cout1);
    fulladder FA2(A[2], B[2], Cout1, S[2], Cout2);
    fulladder FA3(A[3], B[3], Cout2, S[3], Cout3);

endmodule