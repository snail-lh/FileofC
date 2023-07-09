$a = get-childitem * -include *.pdf -recurse
if ($a) {
    <# Action to perform if the condition is true #>
    $i = Read-Host -Prompt "Do you want to delete?"
    if ($i -eq "y") {
        get-childitem * -include *.pdf -recurse | where-object Name -ne "SuperMemoAssistant.Plugins.PDF" | remove-item
    }
    else {
        Write-Output "you don't want to delete"
    }
}
