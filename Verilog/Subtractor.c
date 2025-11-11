
module halfsubtractor(
    input A, B,
    output Bo, D
);

    wire Abar;

    not (Abar, A);
    and(Bo, Abar, B);
    xor (D, A, B);

endmodule

module fullsubtractor(
    input A, B, Bout,
    output Diff, Bin
);

    wire B0, B1, D1;

    halfsubtractor hs1 (A, B, B0, D1);
    halfsubtractor hs2 (D1, Bout, B1, Diff);

    or(Bin, B0, B1);

endmodule
