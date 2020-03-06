<project xmlns="com.autoesl.autopilot.project" name="conv2d_cnn" top="conv2d">
    <files>
        <file name="conv2d_Alg_pad.cpp" sc="0" tb="false" cflags="" blackbox="false"/>
        <file name="types.h" sc="0" tb="false" cflags="" blackbox="false"/>
        <file name="../../MNIST_in_7.dat" sc="0" tb="1" cflags=""/>
        <file name="../../conv1_bias.dat" sc="0" tb="1" cflags=""/>
        <file name="../../conv1_kernel.dat" sc="0" tb="1" cflags=""/>
        <file name="../../conv1_out_7.dat" sc="0" tb="1" cflags=""/>
        <file name="../../conv2d_tb.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

