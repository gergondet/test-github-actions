const { boolean } = require('boolean');
const core = require('@actions/core');
const exec = require('@actions/exec');
const github = require('@actions/github');

async function bash(cmd)
{
  await exec.exec('bash', ['-c', cmd]);
}

async function bash_out(cmd)
{
  let output = '';
  const options = {};
  options.listeners = {
    stdout: (data) => {
      output += data.toString();
    }
  };
  await exec.exec('bash', ['-c', cmd], options);
  return output.trim();
}

async function run()
{
  try
  {
    // Get options
    const with_docker = core.getInput('with-docker');
    const docker_images = core.getInput('docker-images');
    console.log('with-docker ${with_docker}');
    console.log('docker-images ${docker_images}');
  }
  catch(error)
  {
    core.setFailed(error.message);
  }
}

run();
