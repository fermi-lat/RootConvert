# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/RootConvert/RootConvertLib.py,v 1.1 2008/08/15 21:42:36 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['RootConvert'])
    env.Tool('EventLib')
    env.Tool('OnboardFilterTdsLib')
    env.Tool('addLibrary', library = env['obfLibs'])
    env.Tool('addLibrary', library = env['rootLibs'])
    env.Tool('addLibrary', library = env['gaudiLibs'])
    env.Tool('reconRootDataLib')
    env.Tool('digiRootDataLib')
    env.Tool('mcRootDataLib')
def exists(env):
    return 1;
